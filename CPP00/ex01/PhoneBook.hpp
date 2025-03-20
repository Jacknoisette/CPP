/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:56:10 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/20 12:51:50 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <sstream>
# include <iomanip>
# include <cctype>
# include <cstdlib>

class PhoneBook {
private :
	Contact contact[8];
	int contactCount;
public :

    PhoneBook();
	~PhoneBook();
	
	int getContactCount(void) const;
	void 	setContactCount(int nbr);
	
	void	printRow(int row);
	void	printSearch(void);
	void	search(bool print);
	void	add(void);
	void	addContact(const Contact& newContact);
	void	displayPhoneBook(void);
};

#endif