/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:58:19 by jdhallen          #+#    #+#             */
/*   Updated: 2025/04/17 15:21:27 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool	isoperator(char chr)
{
	char operators[4] = {'+', '-', '*', '/'};
	for (int i = 0; i < 4; i++)
		if (chr == operators[i])
			return (true);
	return (false);
}

int	do_operation(int left, int right, char oprtr)
{
	int op;
	char operators[4] = {'+', '-', '*', '/'};
	for (op = 0; op < 4; op++)
		if (oprtr == operators[op])
			break ;
	switch (op)
	{
		case 0 :
			return (left + right);
		case 1 :
			return (left - right);
		case 2 :
			return (left * right);
		case 3 :
			return (left / right);
	}
	throw std::runtime_error("Error: Invalid operator");
	return (0);
}

int	exec_branch(Branch *node){
	if (node == NULL)
		return (0);
	if (!node->getBranchL()->getHav())
		if (exec_branch(node->getBranchL()) == -1)
			return (-1);
	if (!node->getBranchR()->getHav())
		if (exec_branch(node->getBranchR()) == -1)
			return (-1);
	try {
		node->setValue(do_operation(node->getBranchL()->getValue(), node->getBranchR()->getValue(), node->getOprtr()));
		node->setHav(true);
	} catch (std::runtime_error & e) {
		std::cout << e.what() << std::endl;
		return (-1);
	}
	return (0);
}

void	build_branch(std::list<char> &rpn, Branch *node){
	std::list<char>::iterator rpnIt = rpn.end();
	if (node == NULL)
		return;
	rpnIt--;
	char current = *rpnIt;
	rpn.pop_back();
	if (isoperator(current))
	{
		node->setOprtr(current);
		node->setBranchR(new Branch('X', 0, node, NULL, NULL, false));
		build_branch(rpn, node->getBranchR());
		node->setBranchL(new Branch('X', 0, node, NULL, NULL, false));
		build_branch(rpn, node->getBranchL());
	}
	else if (!isoperator(current)){
		node->setValue(current - '0');
		node->setHav(true);
		return ;
	}
	else {
		std::cout << "Error: Invalid char" << std::endl;
		return;
	}
}

bool	build_rpn(std::list<char> &rpn, Branch *trunc)
{
	if (rpn.size() == 1){
		if (std::isdigit(*rpn.begin()))
			trunc->setBranch('X', *rpn.begin() - '0', NULL, NULL, NULL, true);
		else
			return (std::cout << "Error: Invalid char" << std::endl, false);
		return (true);
	}
	build_branch(rpn, trunc);
	return (true);
}

bool	check_rpn(std::list<char> &rpn)
{
	std::list<char>::iterator rpnIt = rpn.begin();
	std::list<char>::iterator rpnEnd = rpn.end();
	while (rpnIt != rpnEnd)
	{
		if (!std::isdigit(*rpnIt) && !isoperator(*rpnIt))
			return (std::cout << "Error: Invalid char" << std::endl, false);
		rpnIt++;
	}
	return (true);
}

bool	init_rpn(const std::string& line, std::list<char> *rpn)
{
	for (unsigned int i = 0; i < line.size(); i++)
	{
		if (i % 2 == 1 && line[i] != ' ')
			return (std::cout << "Error: character" << std::endl, false);
		if (i % 2 == 0 && line[i] == ' ')
			return (std::cout << "Error: space" << std::endl, false);
		if (line[i] != ' ')
			rpn->push_back(line[i]);
	}
	return (true);
}

void display(Branch *actual, const std::string& prefix = "", bool isLeft = true)
{
	if (actual == NULL) 
		return;
	std::cout << prefix;
	std::cout << (isLeft ? "├──" : "└──");
	if (actual->getOprtr() != 'X') {
		std::cout << actual->getOprtr() << std::endl;
	} else if (actual->getHav()) {
		std::cout << actual->getValue() << std::endl;
	} else {
		std::cout << "@" << std::endl;
	}
	if (actual->getBranchL() != NULL) {
		display(actual->getBranchL(), prefix + (isLeft ? "│   " : "	"), true);
	}
	if (actual->getBranchR() != NULL) {
		display(actual->getBranchR(), prefix + (isLeft ? "│   " : "	"), false);
	}
	return ;
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cout << "Error: Wrong Arg" << std::endl, -1);
	std::string	 line = argv[1];
	std::list<char> rpn;
	Branch			trunc;

	if (!init_rpn(line, &rpn))
		return (-1);
	if (!check_rpn(rpn))
		return (-1);
	if (!build_rpn(rpn, &trunc))
		return (-1);
	if (exec_branch(&trunc) == -1)
		return (-1);
	display(&trunc);
	std::cout << trunc.getValue() << std::endl;
	return (0);
}


// Branch *left = new Branch('*', 0 , NULL, NULL, NULL, false);
//	 left->setBranchL(new Branch('X', 1, left, NULL, NULL, true));
//	 left->setBranchR(new Branch('X', 2, left, NULL, NULL, true));

//	 Branch *right = new Branch('X', 3, left, NULL, NULL, true);

//	 Branch *root = new Branch('+', 0, NULL, left, right, false);

//	 // Affichage de l'arbre
//	 display(root);