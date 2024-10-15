/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 00:18:00 by ibertran          #+#    #+#             */
/*   Updated: 2024/10/16 04:05:10 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <stdint.h>

template <typename T>
class PmergeMe {
private:
	T	_c;

	void	_sort(const uint32_t pairSize);
	void	_sortPairs(const uint32_t pairs, const uint32_t pairSize);
	void	_swapPairs(const uint32_t index, const uint32_t pairSize);
	void	_insert(const uint32_t pairs, const uint32_t pairSize);

	void	_pushLeft(const uint32_t pairs, const uint32_t pairSize, T &sorted);
	void	_insertRight(const uint32_t pairs, const uint32_t pairSize, T &sorted);
	void	_insertLeftovers(const uint32_t pairs, const uint32_t pairSize, T &sorted);
	
	static uint32_t	_getInsertIndex(int32_t max, const uint32_t pairSize, const T &sorted, const uint32_t toInsert);

public: 
	PmergeMe(void);
	PmergeMe(const PmergeMe &other);

	~PmergeMe(void);

	PmergeMe	&operator=(const PmergeMe &other);

	bool	addArg(const char *str);
	void	sort(void);
	void	displayContent(void) const;
	void	displayContent(const uint32_t pairSize) const;
	bool	isSorted(void) const;

	const T	&getContainer(void) const;
};

# include "PmergeMe.tpp"

#endif /* ******************************************************************* */
