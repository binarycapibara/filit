// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SuperficialHSet.hpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/17 20:32:26 by ngoguey           #+#    #+#             //
//   Updated: 2016/01/18 19:55:13 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SUPERFICIALHSET_HPP
# define SUPERFICIALHSET_HPP

#include "IComboGen.hpp"

// # include <cstdlib>
// # include <fstream>
// # include <assert.h>

class SuperficialHSet : public IComboGen
{

private:
	/* TYPES ************************ */

	using shapehset_t = PiecesStash::shapehset_t;
	using uidhmap_t = PiecesStash::uidhmap_t;
	using shapemmap_t = PiecesStash::shapemmap_t;

	typedef std::vector<shapemmap_t::const_iterator> uidcombo_t;
	struct HashCombo {
		std::size_t operator () (uidcombo_t const &combo) const {
			std::size_t h = 0;

			for (auto const &it : combo)
				h += std::hash<unsigned int>()(it->second);
			return h;
		}
	};
	typedef std::unordered_set<uidcombo_t, HashCombo> combohset_t;

private:
	/* ATTRIBUTES ******************* */
	PiecesStash const &_ps;
	combohset_t _combosHSet;
	unsigned int const _pc_count;


public:
	/* CONSTRUCTION ***************** */
	SuperficialHSet(PiecesStash const &ps, unsigned int pc_count);
	~SuperficialHSet();

	SuperficialHSet() = delete;
	SuperficialHSet(SuperficialHSet const &src) = delete;
	SuperficialHSet(SuperficialHSet &&src) = delete;
	SuperficialHSet &operator=(SuperficialHSet const &rhs) = delete;
	SuperficialHSet &operator=(SuperficialHSet &&rhs) = delete;

public:
	/* EXPOSED ********************** */
	void giveNextCombo(std::vector<Piece const *> &vec) override;

private:
	/* INTERNAL ********************* */
	unsigned int _randomShape(void) const;
	shapemmap_t::const_iterator _randomPieceOfShape(unsigned int shp) const;
	shapemmap_t::const_iterator _randomUid(void) const;

	/* Circularily increments an iterator over the Multimap */
	shapemmap_t::const_iterator _nextUid(
		shapemmap_t::const_iterator const &it) const;

	/* Generates a combo, may exist in _combosHSet */
	uidcombo_t _randomComboRaw(void) const;

	/* Increments a combo over 1 or more components */
	void _incrementCombo(uidcombo_t &combo, uidcombo_t const &comboRand) const;

	/* Generates a combo, not existing in _combosHSet */
	uidcombo_t _randomCombo(void) const;

};

#endif /* *********************************************** SUPERFICIALHSET_HPP */
