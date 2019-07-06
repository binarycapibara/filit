// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PiecesStash.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/17 16:17:55 by ngoguey           #+#    #+#             //
//   Updated: 2016/01/17 16:22:00 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PIECESSTASH_HPP
# define PIECESSTASH_HPP

# include "Piece.hpp"

# include <map>
# include <unordered_map>
# include <unordered_set>

struct PiecesStash
{
public:
	/* TYPES ************************ */
	typedef std::unordered_set<unsigned int> shapehset_t;
	typedef std::unordered_map<unsigned int, Piece> uidhmap_t;
	typedef std::multimap<unsigned int, unsigned int> shapemmap_t;

private:
	/* ATTRIBUTES ******************* */
	shapehset_t _shapesHSet;
	uidhmap_t _uidsHMap;
	shapemmap_t _shapesMMap;

public:
	/* CONSTRUCTION ***************** */
	PiecesStash();
	~PiecesStash();

	PiecesStash(PiecesStash const &) = delete;
	PiecesStash(PiecesStash &&) = delete;
	auto operator=(PiecesStash const &) = delete;
	auto operator=(PiecesStash &&) = delete;

public:
	/* EXPOSED ********************** */
	static constexpr unsigned int numShape = 19;
	static constexpr unsigned int numValidUid = 113;

	shapehset_t const &shapesHSet(void) const;
	uidhmap_t const &uidsHMap(void) const;
	shapemmap_t const &shapesMMap(void) const;

private:
	/* INTERNAL ********************* */
	void _savePiece (Piece const &pc);
	void _gen(Piece &p, int count, int istart);
};

#endif /* *************************************************** PIECESSTASH_HPP */
