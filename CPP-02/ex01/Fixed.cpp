/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 22:37:47 by lbento            #+#    #+#             */
/*   Updated: 2026/05/07 13:19:24 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
	
const int Fixed::_FractionalBits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_FixedNum = 0;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this=other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_FixedNum = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int param)
{
	std::cout << "Int constructor called" << std::endl;
	this->_FixedNum = param << _FractionalBits;
}

Fixed::Fixed(const float param)
{
	std::cout << "Float constructor called" << std::endl;
	this->_FixedNum = (int)(roundf(param * (1 << _FractionalBits)));
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawbits member function called" << std::endl;
	return (this->_FixedNum);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawbits member function called" << std::endl;
	this->_FixedNum = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)(_FixedNum / (float)(1 <<_FractionalBits)));
}

int	Fixed::toInt(void) const
{
	return ((int)(roundf((float)(_FixedNum >> _FractionalBits))));
}

std::ostream &operator<<(std::ostream &os, const Fixed &obj)
{
	os << obj.toFloat();
	return (os);
}