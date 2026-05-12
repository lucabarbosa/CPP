/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabento <lucabento@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 22:37:47 by lbento            #+#    #+#             */
/*   Updated: 2026/05/12 00:47:58 by lucabento        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
	
const int Fixed::_FractionalBits = 8;

Fixed::Fixed()
{
	this->_FixedNum = 0;
}

Fixed::Fixed(const Fixed &other)
{
	*this=other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_FixedNum = other._FixedNum;
	return (*this);
}

Fixed::~Fixed()
{

}

Fixed::Fixed(const int param)
{
	this->_FixedNum = param << _FractionalBits;
}

Fixed::Fixed(const float param)
{
	this->_FixedNum = (int)(roundf(param * (1 << _FractionalBits)));
}

int	Fixed::getRawBits(void) const
{
	return (this->_FixedNum);
}

void	Fixed::setRawBits(int const raw)
{
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

std::ostream &operator<<(std::ostream &os, const Fixed &other_obj)
{
	os << other_obj.toFloat();
	return (os);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->_FixedNum + other._FixedNum);
	return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->_FixedNum - other._FixedNum);
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	result = Fixed(this->toFloat() * other.toFloat());
	return (result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	result = Fixed(this->toFloat() / other.toFloat());
	return (result);
}

Fixed &Fixed::operator++(void)
{
	this->_FixedNum++;
	return (*this);
}

Fixed &Fixed::operator--(void)
{
	this->_FixedNum--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->_FixedNum++;
	return (temp);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->_FixedNum--;
	return (temp);
}

bool Fixed::operator>(const Fixed &other) const
{
	return (this->_FixedNum > other._FixedNum);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->_FixedNum < other._FixedNum);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->_FixedNum >= other._FixedNum);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->_FixedNum <= other._FixedNum);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->_FixedNum == other._FixedNum);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->_FixedNum != other._FixedNum);
}

Fixed	&Fixed::min(Fixed &a, Fixed&b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed&b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}
