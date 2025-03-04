/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:56:10 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/04 18:42:04 by jdhallen         ###   ########.fr       */
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
public :
	Contact contact[8];
	int contactCount;

    PhoneBook();
	~PhoneBook();
	void	printRow(int row);
	void	printSearch(void);
	void	search(void);
	void	add(void);
	void	addContact(const Contact& newContact);
	void	displayPhoneBook(void);
};

#endif