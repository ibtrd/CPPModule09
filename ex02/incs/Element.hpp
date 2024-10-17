/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Element.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 05:43:30 by ibertran          #+#    #+#             */
/*   Updated: 2024/10/18 00:27:14 by ibertran         ###   ########lyon.fr   */
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

	void	_sort(void);
	
public:
	uint32_t	parent;
	Element(void);
	Element(const Element &other);
	Element(uint32_t value);

	~Element(void);

	Element	&operator=(const Element &other);

	bool	operator<(const Element &other) const;
	bool	operator>(const Element &other) const;

	void		push(uint32_t value);
	void		pair(const Element &other);
	Element<T>	unpair(const uint32_t size);

	void	display(void) const;

	uint32_t	size(void) const;
	uint32_t	pairSize(void) const;
	uint32_t	value(void) const;
};

# include "Element.tpp"

#endif /* ******************************************************************* */

