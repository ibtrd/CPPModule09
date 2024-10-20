/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Element.tpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 05:45:19 by ibertran          #+#    #+#             */
/*   Updated: 2024/10/20 03:18:26 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Element.hpp"

/* CONSTRUCTORS ************************************************************* */

template <template <typename, typename> class T>
Element<T>::Element(void) {}

template <template <typename, typename> class T>
Element<T>::Element(const Element &other) {
	*this = other;
}

template <template <typename, typename> class T>
Element<T>::Element(const uint32_t value) {
	this->_e.push_back(value);
}

template <template <typename, typename> class T>
Element<T>::~Element(void) {}

/* OPERATOR OVERLOADS ******************************************************* */

template <template <typename, typename> class T>
Element<T>	&Element<T>::operator=(const Element &other) {
	if (this == &other)
		return (*this);
	this->_e = other._e;
	return (*this);
}

template <template <typename, typename> class T>
bool	Element<T>::operator==(const uint32_t value) const {
	return (value == this->_e.front());
}

template <template <typename, typename> class T>
bool	Element<T>::operator<(const Element &other) const {
	return (this->_e.front() < other._e.front());
}

template <template <typename, typename> class T>
bool	Element<T>::operator>(const Element &other) const {
	return (this->_e.front() > other._e.front());
}

/* ************************************************************************** */

template <template <typename, typename> class T>
void	Element<T>::_sort(void) {
	if (this->_e.front() > this->_e[this->pairSize()]) {
		return;
	}
	for (uint32_t i = 0; i < this->pairSize(); ++i) {
		const uint32_t swap = this->_e[i];
		this->_e[i] = this->_e[i + this->pairSize()];
		this->_e[i + this->pairSize()] = swap;
	}
}

/* ************************************************************************** */

template <template <typename, typename> class T>
void	Element<T>::push(uint32_t n) {
	this->_e.push_back(n);
}

template <template <typename, typename> class T>
void	Element<T>::pair(const Element &other) {
	for (uint32_t i = 0; i < other._e.size(); ++i) {
		this->_e.push_back(other._e[i]);
	}
	this->_sort();
}

template <template <typename, typename> class T>
Element<T>	Element<T>::unpair(const uint32_t size) {
	Element<T>	unpair;

	for (uint32_t i = 0; i < size; ++i) {
		unpair._e.push_back(this->_e.front());
		this->_e.erase(this->_e.begin());
	}
	unpair._parent = this->value();
	this->_parent = unpair.value();
	return (unpair);
}

/* GETTERS ****************************************************************** */

template <template <typename, typename> class T>
uint32_t	Element<T>::size(void) const {
	return (this->_e.size());
}

template <template <typename, typename> class T>
uint32_t	Element<T>::pairSize(void) const {
	return (this->_e.size() >> 1);
}

template <template <typename, typename> class T>
uint32_t	Element<T>::value(void) const {
	return (this->_e.front());
}

template <template <typename, typename> class T>
uint32_t	Element<T>::getParent(void) const {
	return (this->_parent);
}
