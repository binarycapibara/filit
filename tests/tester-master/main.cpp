// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/13 11:32:11 by ngoguey           #+#    #+#             //
//   Updated: 2016/01/13 19:27:35 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "tester.hpp"

std::unordered_map<std::thread::id, WorkerData*> WorkerData::map; /*static*/
std::mutex WorkerData::map_mutex; /*static*/

int							main(int ac, char *av[])
{
	std::vector<UnitTest> tasks;
	
	std::cout << "Hello World";
	std::cout.flush();
	assert(ac == 5); /* wrong number of arguments to program */
	std::srand(time(0));
	tasks = build_tasks(av);
	run(tasks, av);
	std::cout << "\r";
	report(tasks, av);
	return (0);
}
