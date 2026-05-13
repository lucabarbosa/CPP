/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 14:26:04 by lbento            #+#    #+#             */
/*   Updated: 2026/05/13 14:44:58 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Unnamed")
{
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << "\033[0;33mFragTrap default constructor called\033[0m" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << "\033[0;33mFragTrap default constructor for \033[0m" << this->_name << "\033[0;33m called\033[0m" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "\033[0;33mFragTrap copy constructor called\033[0m" << std::endl;
	*this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "\033[0;33mFragTrap assignment operator called\033[0m" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hit_points = other._hit_points;
		this->_energy_points = other._energy_points;
		this->_attack_damage = other._attack_damage;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "\033[0;33mFragTrap destructor called for \033[0m" << _name << std::endl;
}

void	FragTrap::attack(const std::string &target)
{
	if (this->_energy_points == 0)
	{
		std::cout << this->_name << "\033[0;31m doesn't have energy to attack!\033[0m" << std::endl;
		return ;
	}
	else if (this->_hit_points == 0)
	{
		std::cout << this->_name << "\033[0;31m doesn't have hit points to attack!\033[0m" << std::endl;
		return ;
	}
	else
	{
   	this->_energy_points--;
		std::cout << "\033[0;32mFragTrap \033[0m" << this->_name << "\033[0;32m attacks \033[0m" << target;
		std::cout << "\033[0;32m causing \033[0m" << this->_attack_damage << "\033[0;32m points of damage!\033[0m" << std::endl;
		return ;
	}
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << _name << "\033[0;34m gave a HIGH FIVE GUYS! 👋\033[0m" << std::endl;
}

void	FragTrap::printStatus(void)
{
	if (_hit_points == 0)
	{
		std::cout << this->_name << "\033[0;31m is DIED! ☠\033[0m" << std::endl;
		return ;
	}
	std::cout << "\033[1;35m";
	std::cout << "╔═══════════════════════╗\n";
	std::cout << "║     FRAGTRAP INFO     ║\n";
	std::cout << "╚═══════════════════════╝\n";
	std::cout << "  Name          : " << this->_name << std::endl;
	std::cout << "  Hit Points    : " << this->_hit_points << std::endl;
	std::cout << "  Energy Points : " << this->_energy_points << std::endl;
	std::cout << "  Attack Damage : " << this->_attack_damage << std::endl;
	std::cout << "════════════════════════\033[0m" << std::endl;
}