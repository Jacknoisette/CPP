/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:35:04 by jdhallen          #+#    #+#             */
/*   Updated: 2025/04/29 12:02:00 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//PresidentialPardonForm
PresidentialPardonForm::PresidentialPardonForm(void): AForm("Random Presidential Pardon Form", 25, 5, "Random Guy"){
}

PresidentialPardonForm::PresidentialPardonForm(std::string _name, std::string _target): AForm(_name, 25, 5, _target){
}

PresidentialPardonForm::~PresidentialPardonForm(void){	
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
	: AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExec(), copy.getTarget()){
	*this = copy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src){
	if (this != &src)
		this->setSigned(src.getIsSigned());
	return (*this);
}

void	PresidentialPardonForm::doExecute(void) const{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

