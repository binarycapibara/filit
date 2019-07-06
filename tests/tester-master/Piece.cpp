// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Piece.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/17 16:14:02 by ngoguey           #+#    #+#             //
//   Updated: 2016/01/17 16:24:28 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Piece.hpp"

using P = Piece;

unsigned int P::adjDiff(void) const {
	unsigned int    acc = 0;

	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 3; x++)
			if (val[y][x] == '#' && val[y][x + 1] == '#')
				acc++;
	for (int y = 0; y < 3; y++)
		for (int x = 0; x < 4; x++)
			if (val[y][x] == '#' && val[y + 1][x] == '#')
				acc++;
	return acc;
}

unsigned int P::shape(void) const {
	int             pos = 0;
	unsigned int    h = 0;
	int             fx = -1;
	int             fy = -1;

	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
			if (val[y][x] == '#')
			{
				if (fx < 0)
					fx = x, fy = y;
				else
				{
					h += (x - fx + 2) << 4 * pos++;
					h += (y - fy + 2) << 4 * pos++;
				}
			}
	return h;
}

unsigned int P::uid(void) const {
	unsigned int h = 0;

	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
			h = (h << 1) + (this->val[y][x] == '#' ? 1 : 0);
	return h;
}

void P::dump(std::ofstream &os) const {
	for (auto const &l : val)
		os << l << '\n';
}
