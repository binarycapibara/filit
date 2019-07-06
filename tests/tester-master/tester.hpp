// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   tester.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/14 11:51:01 by ngoguey           #+#    #+#             //
//   Updated: 2016/02/18 14:23:24 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef TESTER_HPP
# define TESTER_HPP

# include <unordered_map>
# include <map>
# include <unordered_set>
# include <set>
# include <vector>

# include <string>
# include <utility>
# include <iostream>
# include <chrono>
# include <sstream>
# include <fstream>
# include <algorithm>
// # include <>

# include <unistd.h>
# include <string.h>
# include <assert.h>
# include <fcntl.h>
# include <errno.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>

# include "ThreadPool.h"
# define NUM_WORKERS std::max(1u, std::thread::hardware_concurrency())
# define WORK_TIMEOUT 1000ms
// using namespace std::chrono_literals;

class UnitTest;

std::vector<UnitTest> build_tasks(char const *const av[]);
void run(std::vector<UnitTest> &tasks, char const *const av[]);
void report(std::vector<UnitTest> const &tasks, char const *const av[]);

class UnitTest
{
public:

	/* CONSTRUCTION ***************** */
	UnitTest(char const *bp, std::string const &av1)
		: binary_path(bp)
		, argv1(av1)
		, timeout{}, status{}, err{}, duration{}, output{}
		{}


	UnitTest(UnitTest &&src)
		: binary_path(src.binary_path)
		, argv1(std::move(src.argv1))
		, timeout{}, status{}, err{}, duration{}, output{}
		{}
	~UnitTest(){}

	UnitTest() = delete;
	UnitTest(UnitTest const &src) = delete;
	UnitTest					&operator=(UnitTest const &rhs) = delete;
	UnitTest					&operator=(UnitTest &&rhs) = delete;

	/* PUBLIC ATTRIBUTES ************ */
	char const *binary_path;
	std::string argv1;

	bool timeout;
	int status[1];
	bool err;
	std::chrono::duration<double, std::milli> duration;
	std::string output;

private:
};
// #ifdef TMPLOL //debug
class WorkerData
{
	/* CONSTRUCTION ***************** */
private:
	WorkerData(){}
public:
	~WorkerData(){}

	WorkerData(WorkerData const &src) = delete;
	WorkerData(WorkerData &&src) = delete;
	WorkerData					&operator=(WorkerData const &rhs) = delete;
	WorkerData					&operator=(WorkerData &&rhs) = delete;

	/* PUBLIC ATTRIBUTES ************ */
	int							pipe[2];

	/* STATIC FUNCTIONS ************* */
	static WorkerData &getWorkerData(std::thread::id id) {
		return *WorkerData::map[id];
	}
	static void initWorkerData(std::thread::id id) {
		WorkerData *const w = new WorkerData;
		int err;
		int flags;

		{
			std::unique_lock<std::mutex> lock(WorkerData::map_mutex);

			WorkerData::map.emplace(id, w);
		}
		err = ::pipe(w->pipe);
		assert(err == 0); /*pipe failed*/
		flags = ::fcntl(w->pipe[0], F_GETFL, 0);
		err = ::fcntl(w->pipe[0], F_SETFL, flags | O_NONBLOCK);;
		assert(err == 0); /*fcntl failed*/
		return ;
	}

private:
	/* STATIC ATTRIBUTES ************ */
	static std::unordered_map<std::thread::id, WorkerData*>	map;
	static std::mutex map_mutex;
};
// #endif //debug
#endif
