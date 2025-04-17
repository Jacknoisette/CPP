/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:27:15 by jdhallen          #+#    #+#             */
/*   Updated: 2025/04/17 14:21:57 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <sstream>

# define RED "\033[1;30m"
# define PURPLE "\033[1;31m"
# define WHITE "\033[1;32m"
# define YELLOW "\033[1;33m"
# define ORANGE "\033[1;34m"
# define PINK "\033[1;35m"
# define LIGHT_GREEN "\033[1;36m"
# define GREY "\033[1;37m"
# define RESET "\033[0m"
# define BIG "\033[1m"

class  Branch {
	private :
		char	oprtr;
		int		value;
		Branch*	parent;
		Branch*	branchL;
		Branch*	branchR;
		bool	have_a_value;
	public :
		Branch(void);
		Branch(char _oprtr, int _value, Branch* _parent, Branch* _branchleft, Branch* _branch_right, bool _hav);
		~Branch(void);
		Branch(const Branch &cpy);
		Branch &operator=(const Branch &src);
		void	compute_branch(void);
		void	compute_leaf(void);
		void	setBranch(char _oprtr, int _value, Branch* _parent, Branch* _branchleft, Branch* _branch_right, bool _hav);
		void	setOprtr(char _oprtr);
		void	setValue(int _value);
		void	setParent(Branch* _parent);
		void	setBranchL(Branch* _branchleft);
		void	setBranchR(Branch* _branch_right);
		void	setHav(bool _hav);
		char	getOprtr(void) const;
		int		getValue(void) const;
		Branch*	getParent(void) const;
		Branch*	getBranchL(void) const;
		Branch*	getBranchR(void) const;
		bool	getHav(void) const;
};

#endif