// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ExhaustiveHeap.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/17 16:25:15 by ngoguey           #+#    #+#             //
//   Updated: 2016/01/17 20:41:08 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef EXHAUSTIVEHEAP_HPP
# define EXHAUSTIVEHEAP_HPP

# include <array>

# include "IComboGen.hpp"

class ExhaustiveHeap : public IComboGen
{

private:
	/* TYPES ************************ */
	struct SubLevel
	{
		unsigned int uid;
		unsigned int count;
	};
	struct Level
	{
		typedef std::array<SubLevel, PiecesStash::numValidUid> array_t;
		array_t sublvls;
	};

private:
	/* ATTRIBUTES ******************* */
	PiecesStash const &_ps;
	std::vector<Level> _heap;
	unsigned int const _npcs;
	unsigned int _count;
	std::vector<unsigned int> _uidCombo;

public:
	/* CONSTRUCTION ***************** */
	ExhaustiveHeap(PiecesStash const &ps, unsigned int npcs);
	~ExhaustiveHeap();

	ExhaustiveHeap() = delete;
	ExhaustiveHeap(ExhaustiveHeap const &src) = delete;
	ExhaustiveHeap(ExhaustiveHeap &&src) = delete;
	ExhaustiveHeap &operator=(ExhaustiveHeap const &rhs) = delete;
	ExhaustiveHeap &operator=(ExhaustiveHeap &&rhs) = delete;

public:
	/* EXPOSED ********************** */
	void giveNextCombo(std::vector<Piece const *> &vec) override;

private:
    /* INTERNAL ********************* */
	void _allocHeap(size_t heap_sizei);
	void _finalizeHeap(unsigned int depth, unsigned int nleaves);
	void _randomPop(std::vector<unsigned int> &combo);

};

#endif /* ************************************************ EXHAUSTIVEHEAP_HPP */
