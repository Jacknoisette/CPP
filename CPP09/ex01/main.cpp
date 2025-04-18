/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:58:19 by jdhallen          #+#    #+#             */
/*   Updated: 2025/04/18 09:52:41 by codespace        ###   ########.fr       */
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
bool check_correct_tree(std::list<char> &rpn)
{
	std::list<char>::iterator rpnIt = rpn.begin();
	std::list<char>::iterator rpnEnd = rpn.end();
	
	int count = 0;
	while (rpnIt != rpnEnd)
	{
		if (isdigit(*rpnIt))
			count++;
		else if (isoperator(*rpnIt))
			count -= 1;
		else
			return (std::cout << "Error: wrong operations" << std::endl, false);

		if (count < 1 && isoperator(*rpnIt))
			return (std::cout << "Error: wrong operations" << std::endl, false);
		rpnIt++;
	}
	if (count == 1)
		return (count == 1);
	return (std::cout << "Error: wrong operations" << std::endl, false);
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
			if (left == 0 || right == 0)
				throw std::runtime_error("Error: Impossible division by 0");
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

int	build_branch(std::list<char> &rpn, Branch *node){
	std::list<char>::iterator rpnIt = rpn.end();
	if (node == NULL)
		return (0);
	rpnIt--;
	char current = *rpnIt;
	rpn.pop_back();
	if (isoperator(current))
	{
		node->setOprtr(current);
		node->setBranchR(new Branch('X', 0, node, NULL, NULL, false));
		if (build_branch(rpn, node->getBranchR()) == -1)
			return (-1);
		node->setBranchL(new Branch('X', 0, node, NULL, NULL, false));
		if (build_branch(rpn, node->getBranchL()) == -1)
			return (-1);
		return (0);
	}
	else if (!isoperator(current)){
		node->setValue(current - '0');
		node->setHav(true);
		return (0);
	}
	else
		return (-1);
	return (0);
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
	if (build_branch(rpn, trunc) == -1)
		return (std::cout << "Error: Invalid char" << std::endl, false);
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
			return (std::cout << "Error: Invalid char" << std::endl, false);
		if (i % 2 == 0 && line[i] == ' ')
			return (std::cout << "Error: Invalid char" << std::endl, false);
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

// int main(int argc, char **argv)
// {
// 	if (argc != 2)
// 		return (std::cout << "Error: Wrong Arg" << std::endl, -1);
// 	std::string	 line = argv[1];
// 	std::list<char> rpn;
// 	Branch			trunc;

// 	if (!init_rpn(line, &rpn))
// 		return (-1);
// 	if (!check_rpn(rpn))
// 		return (-1);
// 	if (!check_correct_tree(rpn))
// 		return (-1);
// 	if (!build_rpn(rpn, &trunc))
// 		return (-1);
// 	display(&trunc);
// 	if (exec_branch(&trunc) == -1)
// 		return (-1);
// 	display(&trunc);
// 	std::cout << trunc.getValue() << std::endl;
// 	return (0);
// }

#include <fstream>
#include <fcntl.h>
int main(int argc, char **argv)
{
	if (argc != 2)
	return (std::cout << "Error: Wrong Arg" << std::endl, -1);
	std::string	filename = argv[1];
	std::ifstream fd1(filename.c_str());
	
	std::string line;
	std::string line2;
	while (std::getline(fd1, line)){
		std::list<char> rpn;
		Branch			trunc;
		std::cout << "\n" << line << std::endl;
		if (!std::getline(fd1, line2))
			return (-1);
		std::cout << line2 << std::endl;
		std::cout << "My result : ";
		if (!init_rpn(line, &rpn))
			continue;
		if (!check_rpn(rpn))
			continue;
		if (!check_correct_tree(rpn))
			continue;
		if (!build_rpn(rpn, &trunc))
			continue;
		if (exec_branch(&trunc) == -1)
			continue;
		// display(&trunc);
		std::cout << trunc.getValue() << std::endl;
	}
	return (0);
}

// Branch *left = new Branch('*', 0 , NULL, NULL, NULL, false);
//	 left->setBranchL(new Branch('X', 1, left, NULL, NULL, true));
//	 left->setBranchR(new Branch('X', 2, left, NULL, NULL, true));

//	 Branch *right = new Branch('X', 3, left, NULL, NULL, true);

//	 Branch *root = new Branch('+', 0, NULL, left, right, false);

//	 // Affichage de l'arbre
//	 display(root);