/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 21:01:45 by ibertran          #+#    #+#             */
/*   Updated: 2024/10/13 00:09:17 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "RPN.hpp"

const char RPN::_operators[OPERATORS] = {'+', '-', '/', '*'};

/* CONSTRUCTORS ************************************************************* */

RPN::RPN(void) {}

RPN::RPN(const RPN &other) {
	*this = other;
}

RPN::RPN(const std::string &str) {
	for (uint32_t i = 0; i < str.size(); ++i) {
		while (std::isspace(str[i]))
			i++;
		if ('\0' == str[i]) {
			break;
		} else  if ('\0' != str[i] && '\0' != str[i + 1] && !std::isspace(str[i + 1])) {
			throw RPNException();
		} else if (std::isdigit(str[i])) {
			this->_stack.push(str[i] - '0');
			continue;
		} else {
			int32_t op;
			for (op = 0; op < OPERATORS; ++op ) {
				if (str[i] == this->_operators[op]) {
					break;
				}
			}
			this->operation(static_cast<RPNop_t>(op));
		}
	}
}

RPN::~RPN(void) {}

/* OPERATOR OVERLOADING ***************************************************** */

RPN	&RPN::operator=(const RPN &other)
{
	if (this == &other)
		return (*this);
	this->_stack = other._stack;
	return (*this);
}

/* ************************************************************************** */

void	RPN::operation(RPNop_t op) {
	if (this->_stack.size() < 2 || OPERATORS == op) {
		throw RPNException();
	}
	int32_t	y = this->_stack.top();
	this->_stack.pop();
	int32_t x = this->_stack.top();
	this->_stack.pop();

	if (ADDITION == op) {
		this->_stack.push(x + y);
	} else if (SUBSTRACTION == op) {
		this->_stack.push(x - y);
	} else if (DIVISION == op) {
		if (y == 0) {
			throw RPNException();
		}
		this->_stack.push(x / y);
	} else if (MULTIPLICATION == op) {
		this->_stack.push(x * y);
	} else {
		throw RPNException();
	}
}

void	RPN::displayTop(void) const {
	if (this->_stack.size() == 0) {
		throw RPNException();
	}
	std::cout << this->_stack.top() << std::endl;
}

/* EXCEPTIONS *************************************************************** */

const char *RPN::RPNException::what(void) const throw() {
	return "Error";
}
