/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:13:27 by jdhallen          #+#    #+#             */
/*   Updated: 2025/04/29 11:45:25 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream> 
# include <exception>
# include <string.h>
# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include <cstdlib>

class RobotomyRequestForm : public AForm{
	public :
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string _name, std::string _target);
		virtual	~RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
		void	doExecute(void) const;
};

#endif