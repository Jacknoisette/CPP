/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:35:04 by jdhallen          #+#    #+#             */
/*   Updated: 2025/04/29 12:01:28 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//ShrubberyCreationForm
ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("Random Shrubbery Creation Form", 145, 137, "Random Bush"){
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _name, std::string _target): AForm(_name, 145, 137, _target){
}

ShrubberyCreationForm::~ShrubberyCreationForm(void){	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
	: AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExec(), copy.getTarget()){
	*this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src){
	if (this != &src)
		this->setSigned(src.getIsSigned());
	return (*this);
}

void	ShrubberyCreationForm::doExecute(void) const{
	std::string		name = this->getTarget();
	for (int i = 0; name[i]; i++)
		if (name[i] == ' ')
			name[i] = '_';
	std::string		filename = name + "_shrubbery";
	std::ofstream	fd(filename.c_str());
	if (fd.is_open()) {
		fd <<   "       _-_\n"
				"    /~~   ~~\\\n"
				" /~~         ~~\\\n"
				"{               }\n"
				" \\  _-     -_  /\n"
				"   ~  \\\\ //  ~\n"
				"_- -   | | _- _\n"
				"  _ -  | |   -_\n"
				"       | |\n"
				"       | |\n";
		fd.close();
	}
}
