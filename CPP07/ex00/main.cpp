/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:44:30 by codespace         #+#    #+#             */
/*   Updated: 2025/04/14 13:15:26 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int	test1(void)
{
	{
		int	x = 0;
		int	y = 42;
		std::cout << "Int : x = " << x << ", y = " << y << std::endl;
		::swap(x, y);
		std::cout << "Int : x = " << x << ", y = " << y << std::endl;
	}
	{
		long	x = 0;
		long	y = 424242424242;
		std::cout << "Long : x = " << x << ", y = " << y << std::endl;
		::swap(x, y);
		std::cout << "Long : x = " << x << ", y = " << y << std::endl;
	}
	{
		char	x = '4';
		char	y = '2';
		std::cout << "Char : x = " << x << ", y = " << y << std::endl;
		::swap(x, y);
		std::cout << "Char : x = " << x << ", y = " << y << std::endl;
	}
	{
		std::string	x = "this is the OG 0";
		std::string	y = "this is not the OG 42";
		std::cout << "Std::string : x = " << x << ", y = " << y << std::endl;
		::swap(x, y);
		std::cout << "Std::string : x = " << x << ", y = " << y << std::endl;
	}
	{
		float	x = 0.0f;
		float	y = 42.42f;
		std::cout << "Float : x = " << x << ", y = " << y << std::endl;
		::swap(x, y);
		std::cout << "Float : x = " << x << ", y = " << y << std::endl;
	}
	{
		double	x = 0.0;
		double	y = 42.42;
		std::cout << "Double : x = " << x << ", y = " << y << std::endl;
		::swap(x, y);
		std::cout << "Double : x = " << x << ", y = " << y << std::endl;
	}

	return (0);
}

int	test2(void)
{
	{
		int	x = 0;
		int	y = 42;
		std::cout << "Int : x = " << x << ", y = " << y << std::endl;
		std::cout << "Min : " << ::min(x, y) << std::endl;
	}
	{
		long	x = 0;
		long	y = 424242424242;
		std::cout << "Long : x = " << x << ", y = " << y << std::endl;
		std::cout << "Min : " << ::min(x, y) << std::endl;
	}
	{
		char	x = '4';
		char	y = '2';
		std::cout << "Char : x = " << x << ", y = " << y << std::endl;
		std::cout << "Min : " << ::min(x, y) << std::endl;
	}
	{
		std::string	x = "this is the OG 0";
		std::string	y = "this is not the OG 42";
		std::cout << "Std::string : x = " << x << ", y = " << y << std::endl;
		std::cout << "Min : " << ::min(x, y) << std::endl;
	}
	{
		float	x = 0.0f;
		float	y = 42.42f;
		std::cout << "Float : x = " << x << ", y = " << y << std::endl;
		std::cout << "Min : " << ::min(x, y) << std::endl;
	}
	{
		double	x = 0.0;
		double	y = 42.42;
		std::cout << "Double : x = " << x << ", y = " << y << std::endl;
		std::cout << "Min : " << ::min(x, y) << std::endl;
	}
	
	return (0);
}

int	test3(void)
{
	{
		int	x = 0;
		int	y = 42;
		std::cout << "Int : x = " << x << ", y = " << y << std::endl;
		std::cout << "Max : " << ::max(x, y) << std::endl;
	}
	{
		long	x = 0;
		long	y = 424242424242;
		std::cout << "Long : x = " << x << ", y = " << y << std::endl;
		std::cout << "Max : " << ::max(x, y) << std::endl;
	}
	{
		char	x = '4';
		char	y = '2';
		std::cout << "Char : x = " << x << ", y = " << y << std::endl;
		std::cout << "Max : " << ::max(x, y) << std::endl;
	}
	{
		std::string	x = "this is the OG 0";
		std::string	y = "this is not the OG 42";
		std::cout << "Std::string : x = " << x << ", y = " << y << std::endl;
		std::cout << "Max : " << ::max(x, y) << std::endl;
	}
	{
		float	x = 0.0f;
		float	y = 42.42f;
		std::cout << "Float : x = " << x << ", y = " << y << std::endl;
		std::cout << "Max : " << ::max(x, y) << std::endl;
	}
	{
		double	x = 0.0;
		double	y = 42.42;
		std::cout << "Double : x = " << x << ", y = " << y << std::endl;
		std::cout << "Max : " << ::max(x, y) << std::endl;
	}
	
	return (0);
}

int	cpp07test(void)
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}

int main(void)
{
	if (test1() == -1)
		std::cout << RED << "test1 failed" << RESET << std::endl;
	else
		std::cout << LIGHT_GREEN << "test1 OK" << RESET << std::endl;
	if (test2() == -1)
		std::cout << RED << "test2 failed " << RESET << std::endl;
	else
		std::cout << LIGHT_GREEN << "test2 OK" << RESET << std::endl;
	if (test3() == -1)
		std::cout << RED << "test3 failed" << RESET << std::endl;
	else
		std::cout << LIGHT_GREEN << "test3 OK" << RESET << std::endl;
	if (cpp07test() == -1)
		std::cout << RED << "cpp07test failed" << RESET << std::endl;
	else
		std::cout << LIGHT_GREEN << "cpp07test OK" << RESET << std::endl;
}
