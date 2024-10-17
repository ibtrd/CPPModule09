/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 04:39:59 by ibertran          #+#    #+#             */
/*   Updated: 2024/10/17 19:50:03 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <ctime>
# include <string>

# include "Element.hpp"

template <template <typename, typename> class T>
class PmergeMe {
private:
	T<Element<T>, std::allocator<Element<T> > > _c;
	std::string									_containerName;
	std::clock_t								_start;


	void	_display(const std::string &str) const;
	void	_display(const std::string &str, const T<Element<T>, std::allocator<Element<T> > > &sorted) const;
	void	_sort(const uint32_t pairSize);
	void	_pair(void);
	void	_insert(const uint32_t size);

	static uint32_t	jacobsthals[66];

public:
	PmergeMe(void);
	PmergeMe(const PmergeMe &other);
	PmergeMe(const std::string &str);

	~PmergeMe(void);

	PmergeMe			&operator=(const PmergeMe &other);
	const Element<T>	&operator[](int index) const;

	bool	addArg(const char *str);
	void	sort(void);
	bool	isSorted(void) const;
};

# include "PmergeMe.tpp"

#endif /* ******************************************************************* */
