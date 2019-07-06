// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   execute.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/14 11:51:03 by ngoguey           #+#    #+#             //
//   Updated: 2016/01/18 19:56:17 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "tester.hpp"
extern char **environ;

static void wait_child(UnitTest &t, pid_t pid
					   , std::chrono::high_resolution_clock::time_point start)
{
	int err;

	while (1) // Waiting child process with timeout
	{
		std::this_thread::yield();
		err = ::waitpid(pid, t.status, WNOHANG);
		t.duration = std::chrono::high_resolution_clock::now() - start;
		if (err == 0)
		{
			if (t.duration > WORK_TIMEOUT)
			{
				(void)::kill(pid, SIGKILL); /*not checking ret*/
				t.timeout = true;
			}
			continue ;
		}
		else if (err == pid)
			break ;
		else
			assert(false); /*waitpid failed*/
	}
	return ;
}

static void child_routine(UnitTest &t, WorkerData &w)
{
	int err;
	char av0[::strlen(t.binary_path) + 1];
	char av1[t.argv1.size() + 1];

	::strcpy(av0, t.binary_path);
	::strcpy(av1, t.argv1.c_str());
	err = ::close(w.pipe[0]);
	assert(err == 0); /*close failed*/
	err = ::dup2(w.pipe[1], 1);
	assert(err == 1); /*dup2 failed*/
	::execve(av0, (char *[]){av0, av1, NULL}, environ);
	std::cerr << "Could not run \"" << av0 << "\"" << std::endl;
	::exit(1);
	return ;
}

static int work(UnitTest &t)
{
	WorkerData &w = WorkerData::getWorkerData(std::this_thread::get_id());
	pid_t pid;
	int err;
	int ret;
	char buf[128];
	auto start = std::chrono::high_resolution_clock::now();

	pid = ::fork();
	if (pid == 0) // Child process
		child_routine(t, w);
	assert(pid > 0); /*fork failed*/
	wait_child(t, pid, start);
	if (WIFSIGNALED(*t.status) && !t.timeout)
		t.err = true;
	do // Retrieving child process output with nonblocking read
	{
		ret = ::read(w.pipe[0], buf, sizeof(buf));
		err = errno;
		t.output.append(buf, ret);
	} while (ret > 0);
	assert(ret == -1 && err == EAGAIN); /*read failed*/
	return 0;
}

void		run(std::vector<UnitTest> &tasks, char const *const [])
{
	ThreadPool p(NUM_WORKERS);

	for (auto const &w : p.getWorkers())
		WorkerData::initWorkerData(w.get_id());
	for (UnitTest &t : tasks)
		p.enqueue(&work, std::ref(t));
	return ;
}
