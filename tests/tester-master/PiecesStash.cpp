// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PiecesStash.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/17 16:14:48 by ngoguey           #+#    #+#             //
//   Updated: 2016/01/18 19:54:34 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "PiecesStash.hpp"

using PS = PiecesStash;

/* CONSTRUCTION ***************** */
PS::PiecesStash() : _shapesHSet{}, _uidsHMap{}, _shapesMMap{}
{
	Piece p = {{"....", "....", "....", "...."}};

	_gen(p, 0, 0);
	return ;
}
PS::~PiecesStash() {}

/* EXPOSED ********************** */
auto PS::shapesHSet(void) const
	-> shapehset_t const & {

	return _shapesHSet;
}
auto PS::uidsHMap(void) const
	-> uidhmap_t const & {

	return _uidsHMap;
}
auto PS::shapesMMap(void) const
	-> shapemmap_t const & {

	return _shapesMMap;
}

/* INTERNAL ********************* */
void PS::_savePiece (Piece const &pc) {

	unsigned int const shape = pc.shape();
	unsigned int const uid = pc.uid();

	_shapesHSet.insert(shape);
	_uidsHMap.insert({uid, pc});
	_shapesMMap.insert({shape, uid});
	return ;
}

void PS::_gen(Piece &p, int count, int istart) {

	int y;
	int x;

	if (count < 4)
	{
		for (int i = istart; i < 16; i++)
		{
			y = i / 4;
			x = i % 4;
			p.val[y][x] = '#';
			_gen(p, count + 1, i + 1);
			p.val[y][x] = '.';
		}
	}
	else if (p.adjDiff() >= 3)
		_savePiece(p);
	return ;
}
