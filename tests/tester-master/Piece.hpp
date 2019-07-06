// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Piece.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/17 16:15:37 by ngoguey           #+#    #+#             //
//   Updated: 2016/01/17 16:45:37 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PIECE_HPP
# define PIECE_HPP

#include <fstream>

struct Piece
{
	char val[4][5];

	/* used to disambiguate valid and invalid pieces */
	unsigned int adjDiff(void) const;

	/* used to disambiguate the 19 different shapes */
	unsigned int shape(void) const;

	/* used to disambiguate the 2^(4*4) different grids */
	unsigned int uid(void) const;

	void dump(std::ofstream &os) const;
};

#endif /* ********************************************************* PIECE_HPP */
