// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ExhaustiveHeap.cpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/17 16:26:13 by ngoguey           #+#    #+#             //
//   Updated: 2016/01/17 20:30:06 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <assert.h>
#include <iostream> //debug

#include "ExhaustiveHeap.hpp"

using EH = ExhaustiveHeap;

template <class T>
static constexpr double dbl(T v) {
	return static_cast<double>(v);
}
template <class T>
static constexpr ssize_t ll(T v) {
	return static_cast<ssize_t>(v);
}
static constexpr size_t powui(size_t const x, size_t e) {

	size_t y = 1;

	while (e-- != 0)
		y *= x;
	return y;
}

/* CONSTRUCTION ***************** */
EH::ExhaustiveHeap(PiecesStash const &ps, unsigned int npcs)
	: IComboGen(), _ps(ps), _heap(), _npcs(npcs), _count(), _uidCombo(npcs)
{
	double const num_leavesf =
		std::pow(dbl(PiecesStash::numValidUid), dbl(npcs));
	double const heap_sizef =
		(1. - num_leavesf) / (1. - dbl(PiecesStash::numValidUid));
	double const mem_reqf =
		heap_sizef * dbl(sizeof(EH::Level));
	size_t const num_leavesi =
		powui(PiecesStash::numValidUid, npcs);
	size_t const heap_sizei =
		(1ll - ll(num_leavesi)) / (1ll - ll(PiecesStash::numValidUid));

	assert(mem_reqf > 0.);
	assert(mem_reqf < std::pow(10., 9.) * 2.);
	_allocHeap(heap_sizei);
  	_finalizeHeap(0, num_leavesi);
	_count = num_leavesi;
	// std::cout << _count << std::endl;
	// std::cout << "" << std::endl;
	// for (auto const &lvl: _heap)
	// {
	// 	std::cout << "LEVEL:" << std::endl;
	// 	for (auto const &sblvl: lvl.sublvls)
	// 		std::cout
	// 			<< sblvl.uid << ", "
	// 			<< sblvl.count << ")" << std::endl;
	// }
	return ;
}

EH::~ExhaustiveHeap(){}

/* EXPOSED ********************** */
void EH::giveNextCombo(std::vector<Piece const *> &vec) {

	int i(0);

	_randomPop(_uidCombo);
	for (unsigned int uid : _uidCombo)
		vec[i++] = &_ps.uidsHMap().at(uid);
	return ;
}


/* INTERNAL ********************* */
void EH::_allocHeap(size_t heap_sizei) {

	Level::array_t def;
	unsigned int j(0);

	for (auto const &it : _ps.uidsHMap())
		def[j++] = {it.first, 42u};
	_heap.resize(heap_sizei, {def});
	return ;
}

void EH::_finalizeHeap(unsigned int depth, unsigned int nleaves) {

	size_t const depth_size = powui(PiecesStash::numValidUid, depth);
	size_t const start_index =
		(1ll - ll(depth_size)) / (1ll - ll(PiecesStash::numValidUid));
	size_t const end_index = start_index + depth_size;
	unsigned int subnleaves = nleaves / PiecesStash::numValidUid;
	unsigned int i;

	// std::cout << "_finalizeHeap:" << std::endl;
	// std::cout << "depth: " << depth<< std::endl;
	// std::cout << "start_index: " << start_index << " -> "
	// 		  << end_index << "(+" << depth_size << ")" << std::endl;
	// std::cout << "subnleaves: " << subnleaves << std::endl;
	i = static_cast<unsigned int>(start_index);
	for (; i != end_index; i++)
	{
		for (unsigned int j = 0; j < PiecesStash::numValidUid; j++)
			_heap[i].sublvls[j].count = subnleaves;
	}
	if (depth < _npcs - 1)
		_finalizeHeap(depth + 1, subnleaves);
	return ;
}

void EH::_randomPop(std::vector<unsigned int> &combo)
{
	unsigned int lvldepthi, lvlcount;

	Level *lvl;
	unsigned int depthsize, depthstarti, choice, sublvl, sum;

	lvldepthi = 0;
	lvlcount = _count;
	assert(_count != 0);
	_count--;
	for (unsigned int depth = 0; depth < _npcs; depth++)
	{
		depthsize = powui(PiecesStash::numValidUid, depth);
		depthstarti =
			(1ll - ll(depthsize)) / (1ll - ll(PiecesStash::numValidUid));
		lvl = &_heap[depthstarti + lvldepthi];
		choice = std::rand() % lvlcount;
		sublvl = 0;
		sum = lvl->sublvls[0].count;
		// std::cout
		// 	<< "depth: " << depth << std::endl
		// 	<< "lvldepthi: " << lvldepthi << std::endl
		// 	<< "lvlcount: " << lvlcount << std::endl
		// 	<< "depthsize: " << depthsize << std::endl
		// 	<< "depthstarti: " << depthstarti << std::endl
		// 	<< "choice: " << choice << std::endl
			// << ": " <<  << std::endl
			// << ": " <<  << std::endl
			// << std::endl;
		while (sum <= choice)
			sum += lvl->sublvls[++sublvl].count;
		lvlcount = lvl->sublvls[sublvl].count;
		lvl->sublvls[sublvl].count--;
		combo[depth] = lvl->sublvls[sublvl].uid;
		lvldepthi = lvldepthi * PiecesStash::numValidUid + sublvl;
	}
	return ;
}
