/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:38:20 by jdhallen          #+#    #+#             */
/*   Updated: 2025/04/17 14:40:55 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

Branch::Branch(void)
	: oprtr('X'), value(0), branchL(NULL), branchR(NULL), have_a_value(false){

 }

Branch::Branch(char _oprtr, int _value, Branch* _parent, Branch* _branchleft, Branch* _branchright, bool _hav)
	: oprtr(_oprtr), value(_value), parent(_parent), branchL(_branchleft), branchR(_branchright), have_a_value(_hav){
}

Branch::~Branch(void){
	if (branchL)
		delete branchL;
	if (branchR)
		delete branchR;
}

Branch::Branch(const Branch &cpy){
	*this = cpy;
}

Branch &Branch::operator=(const Branch &src){
	if (this != &src)
	{
		oprtr = src.oprtr;
		value = src.value;
		parent = src.parent;
		branchL = src.branchL;
		branchR = src.branchR;
		have_a_value = src.have_a_value;
	}
	return (*this);
}

void	Branch::compute_branch(void){
	// if (!have_a_value)

}

void	Branch::compute_leaf(void){
		
}

void	Branch::setBranch(char _oprtr, int _value, Branch* _parent, Branch* _branchleft, Branch* _branchright, bool _hav){
	setOprtr(_oprtr);
	setValue( _value);
	setParent(_parent);
	setBranchL(_branchleft);
	setBranchR(_branchright);
	setHav(_hav);
}

void	Branch::setOprtr(char _oprtr){
	oprtr = _oprtr;
}

void	Branch::setValue(int _value){
	value = _value;
}

void	Branch::setParent(Branch* _parent){
	parent = _parent;
}

void	Branch::setBranchL(Branch* _branchleft){
	branchL = _branchleft;
}

void	Branch::setBranchR(Branch* _branchright){
	branchR = _branchright;
}

void	Branch::setHav(bool _hav){
	have_a_value = _hav;
}

char	Branch::getOprtr(void) const{
	return (oprtr);
}

int	Branch::getValue(void) const{
	return (value);
}

Branch	*Branch::getParent(void) const{
	return (parent);
}

Branch	*Branch::getBranchL(void) const{
	return (branchL);
}

Branch	*Branch::getBranchR(void) const{
	return (branchR);
}

bool	Branch::getHav(void) const{
	return (have_a_value);
}