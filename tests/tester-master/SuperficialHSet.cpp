// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SuperficialHSet.cpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/17 20:37:12 by ngoguey           #+#    #+#             //
//   Updated: 2016/01/18 19:55:49 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "SuperficialHSet.hpp"

// # include <unordered_map>
// # include <map>
// # include <unordered_set>
// # include <set>
// # include <vector>

// # include <cstdlib>
// # include <fstream>
# include <assert.h>

using SHS = SuperficialHSet;

/* CONSTRUCTION ***************** */
SHS::SuperficialHSet(PiecesStash const &ps, unsigned int pc_count)
	: IComboGen(), _ps(ps), _combosHSet{}, _pc_count(pc_count)
	{

	}

SHS::~SuperficialHSet() {}

/* EXPOSED ********************** */
void SHS::giveNextCombo(std::vector<Piece const *> &vec) {

	auto combo = _randomCombo();
	int i = 0;

	for (auto const pc_it : combo)
		vec[i++] = &_ps.uidsHMap().at(pc_it->second);
	_combosHSet.insert(std::move(combo));
	return ;
}

/* INTERNAL ********************* */
unsigned int SHS::_randomShape(void) const {

	int const n = std::rand() % PiecesStash::numShape;
	int i = 0;

	for (auto t : _ps.shapesHSet())
		if (i++ == n)
			return t;
	assert(false); /* should not be reached */
}

SHS::shapemmap_t::const_iterator SHS::_randomPieceOfShape(unsigned int shp) const
{

	unsigned int const n = std::rand() % _ps.shapesMMap().count(shp);
	auto const range = _ps.shapesMMap().equal_range(shp);
	unsigned int i = 0;

	for (auto it = range.first; it != range.second; ++it)
		if (i++ == n)
			return it;
	assert(false); /* should not be reached */
}

SHS::shapemmap_t::const_iterator SHS::_randomUid(void) const {

	return _randomPieceOfShape(_randomShape());
}

SHS::shapemmap_t::const_iterator SHS::_nextUid(
	shapemmap_t::const_iterator const &it) const {

	shapemmap_t::const_iterator ret;

	ret = std::next(it);
	if (ret == _ps.shapesMMap().end())
		return _ps.shapesMMap().begin();
	return ret;
}

SHS::uidcombo_t SHS::_randomComboRaw(void) const {

	uidcombo_t ret;

	for (unsigned int i = 0; i < _pc_count; i++)
		ret.push_back(_randomUid());
	return ret;
}

void SHS::_incrementCombo(uidcombo_t &combo, uidcombo_t const &comboRand) const {

	int level;
	shapemmap_t::const_iterator it;

	level = _pc_count;
	do {
		--level;
		combo[level] = _nextUid(combo[level]);
	} while (combo[level] == comboRand[level]);
	return ;
}

SHS::uidcombo_t SHS::_randomCombo(void) const {

	uidcombo_t const comboRand(_randomComboRaw());
	uidcombo_t combo(comboRand);

	while (_combosHSet.find(combo) != _combosHSet.end())
		_incrementCombo(combo, comboRand);
	return combo;
}
