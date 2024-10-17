/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 04:40:59 by ibertran          #+#    #+#             */
/*   Updated: 2024/10/18 00:50:20 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <cerrno>
#include <algorithm>

#include "PmergeMe.hpp"

template <template <typename, typename> class T>
 uint32_t	PmergeMe<T>::jacobsthals[66] = {1, 3, 5, 11, 21, 43, 85, 171, 341,
 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};

/* CONSTRUCTORS ************************************************************* */

template <template <typename, typename> class T>
PmergeMe<T>::PmergeMe(void) {
	this->_start = std::clock();
}

template <template <typename, typename> class T>
PmergeMe<T>::PmergeMe(const PmergeMe &other) {
	*this = other;
}

template <template <typename, typename> class T>
PmergeMe<T>::PmergeMe(const std::string &str) {
	this->_start = std::clock();
	this->_containerName = str;
}

template <template <typename, typename> class T>
PmergeMe<T>::~PmergeMe(void) {}

/* OPERATOR OVERLOADS ******************************************************* */

template <template <typename, typename> class T>
PmergeMe<T>	&PmergeMe<T>::operator=(const PmergeMe &other) {
	if (this == &other)
		return (*this);
	this->_c = other.c;
	return (*this);
}

template <template <typename, typename> class T>
const Element<T>	&PmergeMe<T>::operator[](int index) const {
	return (this->_c[index]);
}


/* ************************************************************************** */

template <template <typename, typename> class T>
void	PmergeMe<T>::_sort(const uint32_t size) {
	this->_pair();
	// this->_display("paired:\t");
	if (this->_c.size() > 1 && (*this)[1].size() == (size << 1)) {
		this->_sort(size << 1);
	}
	this->_insert(size << 1);
	// this->_display("insert:\t");
}

template <template <typename, typename> class T>
void	PmergeMe<T>::_pair(void) {
	for (uint32_t i = 0; i + 1 < this->_c.size(); ++i) {
		this->_c[i].pair(this->_c[i + 1]);
		this->_c.erase(this->_c.begin() + i + 1);
	}
}

template <template <typename, typename> class T>
void	PmergeMe<T>::_insert(const uint32_t size) {
	T<Element<T>, std::allocator<Element<T> > > sorted;
	Element<T>									unpair;
	Element<T>									remainder;

	this->_display("\tSTART: ");
	// std::cout << std::endl;
	
	// unpair = this->_c.front().unpair();
	// this->_c.insert(this->_c.begin(), unpair);
	// for (uint32_t i = 2; i < this->_c.size(); i += 2) {
	// 		// std::cout << "inserting: " << this->_c[i].size() << "\t";
	// 	if (this->_c[i].size() == size) {
	// 		unpair = this->_c[i].unpair();
	// 		this->_c.insert(std::lower_bound(this->_c.begin(), this->_c.begin() + i, unpair), unpair);
	// 		// this->_display("\t\t THEN:   ");
	// 	} else if (this->_c[i].size() >= (size >> 1)) {
	// 		unpair = this->_c[i].unpair(size >> 1);
	// 		if (this->_c[i].size() == 0) {
	// 			this->_c.pop_back();
	// 		}
	// 		this->_c.insert(std::lower_bound(this->_c.begin(), this->_c.begin() + i, unpair), unpair);
	// 		// this->_display("\t\t THEN:   ");
	// 	}
	// }

	for (uint32_t i = 0; i < this->_c.size() - 1; ++i) {
		unpair = this->_c[i].unpair(size >> 1);
		sorted.push_back(unpair);
	}
	if (this->_c.back().size() == size) {
		unpair = this->_c.back().unpair(size >> 1);
		sorted.push_back(unpair);
	} else {
		remainder = this->_c.back();
		this->_c.pop_back();
	}

	sorted.insert(sorted.begin(), this->_c.front());
	uint32_t j = 1;
	while (PmergeMe<T>::jacobsthals[j - 1] < this->_c.size()) {
		uint32_t	end = PmergeMe<T>::jacobsthals[j - 1];
		// std::cout << jacobsthals[j] << "=" << jacobsthals[j - 1] << " | ";
		// this->_display("\tJACOB: ", sorted);
		
		for (uint32_t start = PmergeMe<T>::jacobsthals[j] - 1; start >= end; --start) {
			uint32_t offset= 0;
			// std::cout << "\tjacob=" << start;
			if (start >= this->_c.size()) {
				// std::cout << " outofrange (size=" << this->_c.size() << ")" << std::endl;
				continue;
			} else if (this->_c[start].size() == (size >> 1)) {
				typename T<Element<T>, std::allocator<Element<T> > >::reverse_iterator	it = sorted.rbegin();
				int i = 0;
				while (it != sorted.rend()) {
					std::cout << it->value() << " ";
					++i;
					++it;	
				}
				std::cout << i << std::endl;
				// std::cout << " inserting " << this->_c[start].value() << "| PAR= " << (sorted.begin() + (start * 2))->value() << std::endl;
				sorted.insert(std::lower_bound(sorted.begin(), sorted.begin() + start + 3, this->_c[start]), this->_c[start]);
				// this->_display("\tsorted->: ", sorted);
			}
			++offset;
		}		
		// std::cout << std::endl;
		j++;
	}
	
	if (remainder.size()) {
		if (remainder.size() >= (size >> 1)) {
			unpair = remainder.unpair(size >> 1);
			sorted.insert(std::lower_bound(sorted.begin(), sorted.end(), unpair), unpair);
		}
		if (remainder.size()) {
			sorted.push_back(remainder);
		}
	}
	this->_c = sorted;
	
	this->_display("END-> ");
	std::cout << std::endl;
}

template <template <typename, typename> class T>
void	PmergeMe<T>::_display(const std::string &str) const {
	std::cout << str;
	for(uint32_t i = 0; i < this->_c.size(); ++i) {
		this->_c[i].display();
		std::cout << " ";
	}
	std::cout << (this->isSorted() ? "✅" : "❌") << std::endl;
}

template <template <typename, typename> class T>
void	PmergeMe<T>::_display(const std::string &str, const T<Element<T>, std::allocator<Element<T> > > &sorted) const {
	std::cout << str;
	for(uint32_t i = 0; i < sorted.size(); ++i) {
		sorted[i].display();
		std::cout << " ";
	}
	std::cout << std::endl;
	// std::cout << (this->isSorted() ? "✅" : "❌") << std::endl;
}

/* ************************************************************************** */

template <template <typename, typename> class T>
bool	PmergeMe<T>::addArg(const char *str) {
	long	value;
	char	*endPtr;

	errno = 0;
	value = strtol(str, &endPtr, 10);
	if (!*str || errno || *endPtr != '\0' || value < 0 || value > UINT32_MAX) {
		return true;
	}

	this->_c.push_back(Element<T>(value));
	return false;
}

template <template <typename, typename> class T>
void	PmergeMe<T>::sort(void) {
	this->_display("Before:\t");
	if (this->_c.size() > 1) {
		this->_sort(1);
	}
	double duration = (clock() - this->_start) / static_cast<double>(CLOCKS_PER_SEC);
	this->_display("After:\t");
	std::cout << "Time to process a range of " << this->_c.size()
		<< " elements with " << this->_containerName
		<< " : " << std::fixed << duration << "s" << std::endl;
}

template <template <typename, typename> class T>
bool	PmergeMe<T>::isSorted(void) const {
	for (uint32_t i = 0; (i + 1) < this->_c.size(); ++i) {
		if ((*this)[i] > (*this)[i + 1]) {
			return (false);
		}
	}
	return (true);
}
