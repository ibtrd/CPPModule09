/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 04:39:59 by ibertran          #+#    #+#             */
/*   Updated: 2024/10/16 09:11:17 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <stdint.h>
# include <string>

# include "Element.hpp"

template <template <typename, typename> class T>
class PmergeMe {
private:
	T<Element<T>, std::allocator<Element<T> > > _c;

	void	_display(const std::string &str) const;
	void	_sort(const uint32_t pairSize);
	void	_pair(void);
	void	_insert(const uint32_t size);

public:
	PmergeMe(void);
	PmergeMe(const PmergeMe &other);

	~PmergeMe(void);

	PmergeMe	&operator=(const PmergeMe &other);
	const Element<T>	&operator[](int index) const;

	bool	addArg(const char *str);
	void	sort(void);
	bool	isSorted(void) const;
};

# include "PmergeMe.tpp"

#endif /* ******************************************************************* */
