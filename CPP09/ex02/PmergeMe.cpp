/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:45:45 by jdhallen          #+#    #+#             */
/*   Updated: 2025/04/23 13:06:17 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

long getTimeMicro(void){
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (static_cast<long>(tv.tv_sec) * 1000000 + static_cast<long>(tv.tv_usec));
}