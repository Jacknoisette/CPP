/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 08:09:58 by codespace         #+#    #+#             */
/*   Updated: 2025/04/11 08:54:31 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <ostream>

class Data {
	private :
		std::string name;
		const	int	nbr;
	public :
		static int	data_nbr;
		Data(void);
		Data(std::string _name, int _nbr);
		~Data(void);
		Data(const Data &cpy);
		std::string	getName(void) const;
		int			getNbr(void) const;
		Data &operator=(const Data &src);
};

std::ostream& operator<<(std::ostream& os, const Data& obj);

#endif