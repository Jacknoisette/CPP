/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:21:10 by jdhallen          #+#    #+#             */
/*   Updated: 2025/04/09 16:01:02 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

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

class Form {
	private :
		const std::string	name;
		const int			grade_to_sign;
		const int			grade_to_exec;
		bool				is_signed;

	public :
		Form(void);
		Form(std::string _name, int _grade_to_sign, int _grade_to_exec);
		virtual	~Form(void);
		Form(const Form &copy);
		Form &operator=(const Form &src);
		const std::string	getName(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExec(void) const;
		bool				getIsSigned(void) const;
		void				beSigned(Bureaucrat &executor);
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

std::ostream& operator<<(std::ostream& os, Form& obj);

#endif