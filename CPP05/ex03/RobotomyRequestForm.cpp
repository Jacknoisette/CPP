/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:13:17 by jdhallen          #+#    #+#             */
/*   Updated: 2025/04/09 14:47:57 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//RobotomyRequestForm
RobotomyRequestForm::RobotomyRequestForm(void): AForm("Random Robotomy Form", 72, 45, "Random Robot"){
	std::srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(std::string _name, std::string _target): AForm(_name, 72, 45, _target){
	std::srand(time(NULL));
}

RobotomyRequestForm::~RobotomyRequestForm(void){	
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
	: AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExec(), copy.getTarget()){
	*this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src){
	if (this != &src)
		this->setSigned(src.getIsSigned());
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const{
	if (!this->getIsSigned() || executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException("Robotomy Form" + this->getName() + " cannot be execute by " + executor.getName() + " because he's grade");
	
	std::cout << executor.getName() << " execute " << this->getName() << std::endl;
	int	chance = (std::rand() % 2 == 1);
	std::cout << "BZRRZZZRBRZZZZZZZZZBRRRB (Drilling Noises...)" << std::endl;
	if (chance == 1)
		std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->getTarget() << " has been robotomized unsuccessfully, it failed" << std::endl;
}
