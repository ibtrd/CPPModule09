/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Element.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 05:43:30 by ibertran          #+#    #+#             */
/*   Updated: 2024/10/20 03:20:17 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENT_HPP
# define ELEMENT_HPP

# include <stdint.h>
# include <ostream>

template <template <typename, typename> class T>
class Element {
private:
	T<uint32_t, std::allocator<uint32_t> > 	_e;
	uint32_t								_parent;

	void	_sort(void);
	
public:
	Element(void);
	Element(const Element &other);
	Element(uint32_t value);

	~Element(void);

	Element	&operator=(const Element &other);

	bool	operator==(const uint32_t value) const;
	bool	operator<(const Element &other) const;
	bool	operator>(const Element &other) const;

	void		push(uint32_t value);
	void		pair(const Element &other);
	Element<T>	unpair(const uint32_t size);

	uint32_t	size(void) const;
	uint32_t	pairSize(void) const;
	uint32_t	value(void) const;
	uint32_t	getParent(void) const;
};

# include "Element.tpp"

#endif /* ******************************************************************* */

