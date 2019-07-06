// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IComboGen.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/17 20:25:47 by ngoguey           #+#    #+#             //
//   Updated: 2016/01/17 20:30:11 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ICOMBOGEN_HPP
# define ICOMBOGEN_HPP

# include <vector>

# include "Piece.hpp"
# include "PiecesStash.hpp"

class IComboGen
{

public:
	/* CONSTRUCTION ***************** */
	virtual ~IComboGen() {}

public:
	/* EXPOSED ********************** */
	virtual void giveNextCombo(std::vector<Piece const *> &vec) = 0;
};

#endif /* ***************************************************** ICOMBOGEN_HPP */
