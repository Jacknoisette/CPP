/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:29:56 by jdhallen          #+#    #+#             */
/*   Updated: 2025/05/15 10:20:40 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

//FException
FException::FException(const std::string &_message): message(_message){
}

const char *FException::what(void) const throw(){
	return (message.c_str());
}

FException::~FException(void) throw(){
}

//GradeTooHighException
AForm::GradeTooHighException::GradeTooHighException(std::string message): FException(message + " is too high !"){
}

AForm::GradeTooHighException::~GradeTooHighException(void) throw(){
}

//GradeTooLowException
AForm::GradeTooLowException::GradeTooLowException(std::string message): FException(message + " is too low !"){
}

AForm::GradeTooLowException::~GradeTooLowException(void) throw(){
}

//AForm
AForm::AForm(void): name("Random Form"), grade_to_sign(150), grade_to_exec(150), is_signed(false), target("Random Target"){
}

AForm::AForm(std::string _name, int _grade_to_sign, int _grade_to_exec, std::string	_target)
	: name(_name), grade_to_sign(_grade_to_sign), grade_to_exec(_grade_to_exec), is_signed(false), target(_target){
	if (grade_to_sign < 1)
		throw GradeTooHighException("Form grade to sign");
	if (grade_to_exec < 1)
		throw GradeTooHighException("Form grade to execute");
	if (grade_to_sign > 150)
		throw GradeTooLowException("Form grade to sign");
	if (grade_to_exec > 150)
		throw GradeTooLowException("Form grade to execute");
}

AForm::~AForm(void){	
}

AForm::AForm(const AForm &copy)
	: name(copy.name), grade_to_sign(copy.grade_to_sign), grade_to_exec(copy.grade_to_exec){
	*this = copy;
}

AForm &AForm::operator=(const AForm &src){
	if (this != &src)
		this->is_signed = src.is_signed;
	return (*this);
}

const std::string	AForm::getName(void) const{
	return (name);
}

int	AForm::getGradeToSign(void) const{
	return (grade_to_sign);
}

int	AForm::getGradeToExec(void) const{
	return (grade_to_exec);
}

bool	AForm::getIsSigned(void) const{
	return (is_signed);
}

std::string	AForm::getTarget(void) const{
	return (target);
}

void	AForm::beSigned(Bureaucrat &executor){
	if (executor.getGrade() > this->getGradeToSign())
		throw GradeTooLowException("Bureaucrat " + executor.getName() + " grade to sign");
	if (!this->getIsSigned())
	{
		this->is_signed = true;
		std::cout << executor.getName() << " signed " << this->getName() << std::endl;
	}
	else
		std::cout << executor.getName() << " couldn't sign " << this->getName() << " because it was already sign !" <<  std::endl;
}

void	AForm::setSigned(bool value){
	this->is_signed = value;
}

std::ostream& operator<<(std::ostream& output, const AForm& obj){
	output << obj.getName() << ",";
	if (obj.getIsSigned())
		output << " is signed";
	else
		output << " is not signed";
	output << ", the grade to sign is " << obj.getGradeToSign();
	output << " and the grade to exec is " << obj.getGradeToExec() << ". ";
	return (output);
}

void	AForm::execute(Bureaucrat const &executor) const{
	if (!this->getIsSigned())
		throw GradeTooLowException("Form " + this->getName() + " cannot be execute by " + executor.getName() + " because he's not signed");
	if (executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException("Form " + this->getName() + " cannot be execute by " + executor.getName() + " because he's grade");
	this->doExecute();
}