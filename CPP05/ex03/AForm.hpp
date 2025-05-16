/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:30:11 by jdhallen          #+#    #+#             */
/*   Updated: 2025/05/15 10:28:32 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream> 
# include <exception>
# include <string.h>
# include "Bureaucrat.hpp"

class FException : public std::exception {
	protected:
		std::string message;
	public :
		FException(const std::string &_message);
		virtual ~FException(void) throw();
		virtual const char *what(void) const throw();
};

class AForm {
	private :
		const std::string	name;
		const int			grade_to_sign;
		const int			grade_to_exec;
		bool				is_signed;
		std::string			target;

	public :
		AForm(void);
		AForm(std::string _name, int _grade_to_sign, int _grade_to_exec, std::string _target);
		virtual	~AForm(void);
		AForm(const AForm &copy);
		AForm &operator=(const AForm &src);
		const std::string	getName(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExec(void) const;
		bool				getIsSigned(void) const;
		std::string			getTarget(void) const;
		void				beSigned(Bureaucrat &executor);
		void				setSigned(bool value);
		void				execute(Bureaucrat const &executor) const;
		virtual void		doExecute(void) const = 0;
		class GradeTooHighException : public FException {
			public :
				GradeTooHighException(std::string message);
				virtual ~GradeTooHighException(void) throw();
		};
		class GradeTooLowException : public FException {
			public :
				GradeTooLowException(std::string message);
				virtual ~GradeTooLowException(void) throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif