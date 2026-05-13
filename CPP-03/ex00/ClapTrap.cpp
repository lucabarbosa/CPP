/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 19:22:29 by lbento            #+#    #+#             */
/*   Updated: 2026/05/13 12:59:04 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Unname"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "\033[0;33mClapTrap default constructor called\033[0m" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "\033[0;33mClapTrap default constructor for \033[0m" << this->_name << "\033[0;33m called\033[0m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hit_points = other._hit_points;
		this->_energy_points = other._energy_points;
		this->_attack_damage = other._attack_damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "\033[0;33mClapTrap destructor called for \033[0m" << _name << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (_energy_points == 0)
	{
		std::cout << this->_name << "\033[0;31m doesn't have energy to attack!\033[0m" << std::endl;
		return ;
	}
	else if (_hit_points == 0)
	{
		std::cout << this->_name << "\033[0;31m doesn't have hit points to attack!\033[0m" << std::endl;
		return ;
	}
	else
	{
   	this->_energy_points--;
		std::cout << this->_name << "\033[0;32m attacks \033[0m" << target << "\033[0;32m causing \033[0m";
		std::cout << this->_attack_damage << "\033[0;32m points of damage!\033[0m" << std::endl;
		return ;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= _hit_points)
		_hit_points = 0;
	if (_hit_points == 0)
	{
		std::cout << this->_name << "\033[0;31m doesn't have hit points. \033[0m" << this->_name;
		std::cout << "\033[0;31m is already dead!\033[0m" << std::endl;
		return ;
	}
	this->_hit_points -= amount;
	std::cout << this->_name << "\033[0;32m took \033[0m" << amount << "\033[0;32m of damage!\033[0m" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit_points == 0)
	{
		std::cout << this->_name << "\033[0;31m doesn't have hit points. \033[0m" << this->_name;
		std::cout << "\033[0;31m is already dead!\033[0m" << std::endl;
		return ;
	}
	if (_energy_points == 0)
	{
		std::cout << _name << "\033[0;31m doesn't have enough energy to make repairs!\033[0m" << std::endl;
		return ;
	}
	this->_hit_points += amount;
	this->_energy_points--;
	std::cout << _name << "\033[0;36m repaired \033[0m" << amount << "\033[0;36m of hit points. Your current health is \033[0m";
	std::cout << this->_hit_points << "\033[0;36m hit points.\033[0m" << std::endl;
}

void	ClapTrap::printStatus(void)
{
	if (_hit_points == 0)
	{
		std::cout << this->_name << "\033[0;31m is DIED! ☠\033[0m" << std::endl;
		return ;
	}
	std::cout << "\033[1;35m";
	std::cout << "╔══════════════════════╗\n";
	std::cout << "║    CHARACTER INFO    ║\n";
	std::cout << "╚══════════════════════╝\n";
	std::cout << "  Name          : " << this->_name << std::endl;
	std::cout << "  Hit Points    : " << this->_hit_points << std::endl;
	std::cout << "  Energy Points : " << this->_energy_points << std::endl;
	std::cout << "  Attack Damage : " << this->_attack_damage << std::endl;
	std::cout << "═══════════════════════\033[0m" << std::endl;
}
