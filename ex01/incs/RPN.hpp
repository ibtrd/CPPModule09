/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 21:01:29 by ibertran          #+#    #+#             */
/*   Updated: 2024/10/12 23:57:50 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>
#include <stdint.h>

typedef enum {
	ADDITION,
	SUBSTRACTION,
	DIVISION,
	MULTIPLICATION,
	OPERATORS
}	RPNop_t;

class RPN {
private:
	const static char 	_operators[OPERATORS];
	std::stack<int32_t>	_stack;

public:
	RPN(void);
	RPN(const RPN &);
	RPN(const std::string &str);

	~RPN(void);

	RPN	&operator=(const RPN &);

	void	operation(RPNop_t op);
	void	displayTop(void) const;

	class RPNException : public std::exception {
		const char *what(void) const throw();
	};
};

#endif /* ******************************************************************* */
