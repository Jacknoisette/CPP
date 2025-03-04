/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:32:48 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/04 17:57:29 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <sstream>
# include <iomanip>
# include <cctype>
# include <cstdlib>

class Contact {
	private :
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
	public :

		std::string	getFirstName(void) const;
		std::string	getLastName(void) const;
		std::string	getNickname(void) const;
		std::string	getPhoneNumber(void) const;
		std::string	getDarkestSecret(void) const;

		void	setFirstName(std::string str);
		void	setLastName(std::string str);
		void	setNickname(std::string str);
		void	setPhoneNumber(std::string str);
		void	setDarkestSecret(std::string str);
		void	changeContact(void);
		void	display(void) const;
};

#endif