/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:12:36 by jdhallen          #+#    #+#             */
/*   Updated: 2025/05/15 10:28:02 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream> 
# include <exception>
# include <string.h>

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
		Bureaucrat(int _grade);
		Bureaucrat(std::string _name);
		Bureaucrat(std::string _name, int _grade);
		~Bureaucrat(void);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &src);
		const std::string	getName() const;
		int					getGrade() const;
		void				incrementGrade(int increment);
		void				decrementGrade(int decrement);
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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif