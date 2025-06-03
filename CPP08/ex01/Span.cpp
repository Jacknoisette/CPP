/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:03:52 by jdhallen          #+#    #+#             */
/*   Updated: 2025/06/02 15:03:34 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : max_size(0){
}

Span::Span(unsigned int N) : max_size(N){
}

Span::~Span(void){
}

Span::Span(const Span &cpy){
	*this = cpy;
}

Span &Span::operator=(const Span &src){
	if (this != &src)
	{
		max_size = src.max_size;
		span = src.span;
	}
	return (*this);
}

void	Span::addNumber(int nbr){
	if (span.size() < max_size)
		span.push_back(nbr);
	else
		throw std::runtime_error("Span is full");
}

void	Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end){
	unsigned int distance = std::distance(begin, end);
	if (distance + span.size() <= max_size)
		span.insert(span.end(), begin, end);
	else
		throw std::runtime_error("Span can't store all those informations");
}

unsigned int		Span::shortestSpan(void){
	std::vector<int> temp = span;
	if (temp.size() < 2)
		throw std::runtime_error("Span size is not big enough");
	std::sort(temp.begin(), temp.end());
	unsigned int shortest = std::numeric_limits<unsigned int>::max();
	for (unsigned int i = 1; i < temp.size(); i++){
		unsigned int diff = abs(temp[i] - temp[i - 1]);
		if (diff < shortest)
			shortest = diff;
	}
	return (shortest);
}

unsigned int		Span::longestSpan(void){
	std::vector<int> temp = span;
	if (temp.size() < 2)
		throw std::runtime_error("Span size is not big enough");
	std::sort(temp.begin(), temp.end());
	return (abs(temp[temp.size() - 1] - *temp.begin()));	
}

std::vector<int>	Span::getSpan(void) const{
	return (span);
}