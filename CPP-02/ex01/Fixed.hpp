/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 22:37:56 by lbento            #+#    #+#             */
/*   Updated: 2026/05/07 13:20:27 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	_FixedNum;
		static const int _FractionalBits;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		Fixed (const int param);
		Fixed (const float param);
		int	getRawBits(void) const;
		void setRawBits(int const raw);
		float	toFloat(void) const;
		int	toInt(void) const;
};
	
std::ostream &operator<<(std::ostream &os, const Fixed &obj);

#endif