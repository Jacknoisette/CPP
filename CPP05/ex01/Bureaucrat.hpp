/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:12:36 by jdhallen          #+#    #+#             */
/*   Updated: 2025/04/09 12:04:15 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream> 
# include <exception>
# include <string.h>

#define RED "\033[1;30m"
#define PURPLE "\033[1;31m"
#define WHITE "\033[1;32m"
#define YELLOW "\033[1;33m"
#define ORANGE "\033[1;34m"
#define LIGHT_YELLOW "\033[1;35m"
#define LIGHT_GREEN "\033[1;36m"
#define GREY "\033[1;37m"
#define RESET "\033[0m"

class Form;

class BException : public std::exception {
	protected:
		std::string message;
	public :
		BException(const std::string &_message);
		virtual ~BException(void) throw();
		virtual const char *what(void) const throw();
};

class Bureaucrat {
	private :
		const std::string	name;
		int					grade;

	public :
		Bureaucrat(void);
		Bureaucrat(std::string _name, int _grade);
		~Bureaucrat(void);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &src);
		const std::string	getName() const;
		int					getGrade() const;
		void				incrementGrade(int increment);
		void				decrementGrade(int decrement);
		void				signForm(Form &form);
		class GradeTooHighException : public BException {
			public :
				GradeTooHighException(void);
				virtual ~GradeTooHighException(void) throw();
		};
		class GradeTooLowException : public BException {
			public :
				GradeTooLowException(void);
				virtual ~GradeTooLowException(void) throw();
		};
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& obj);

#endif