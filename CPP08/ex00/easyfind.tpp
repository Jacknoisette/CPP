/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:09:26 by jdhallen          #+#    #+#             */
/*   Updated: 2025/04/15 11:39:06 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
void	easyfind(T container, int integer){
	typename T::iterator result = std::find(container.begin(), container.end(), integer);
	if (result == container.end())
		throw std::runtime_error("The value was not found in the container");
	int position = std::distance(container.begin(), result);
	std::cout << "The integer " << integer << " was found at position " << position << " in the container" << std::endl;
}
