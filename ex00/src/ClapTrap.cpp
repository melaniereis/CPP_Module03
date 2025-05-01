/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:30:12 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/01 14:36:21 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << GRN "✅ Default constructor called" RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << GRN "✅ Name constructor called" RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &rhs)
{
	*this = rhs;
	std::cout << YEL "📋 Copy constructor called" RESET << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	std::cout << YEL "🔁 Copy assignment operator called" RESET << std::endl;
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << RED "❌ Destructor called for " << _name << RESET << std::endl;
}

std::string ClapTrap::getName(void) const
{
	return _name;
}

unsigned int ClapTrap::getHitPoints(void) const
{
	return _hitPoints;
}

unsigned int ClapTrap::getEnergyPoints(void) const
{
	return _energyPoints;
}
unsigned int ClapTrap::getAttackDamage(void) const
{
	return _attackDamage;
}

bool ClapTrap::has_points(void) const
{
	if (_hitPoints == 0)
	{
		std::cout << RED "💀 " << _name << " has no hit points left and cannot act!" RESET << std::endl;
		return false;
	}
	if (_energyPoints == 0)
	{
		std::cout << RED "⚠️  " << _name << " has no energy left!" RESET << std::endl;
		return false;
	}
	return true;
}

void ClapTrap::attack(const std::string &target)
{
	if (!has_points())
		return;
	--_energyPoints;

	std::cout << CYN "🗡️  " << _name
			  << " attacks " << target << ", causing "
			  << RED << _attackDamage << " damage!" RESET
			  << " (EP: " << YEL << _energyPoints << RESET << ")" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!has_points())
		return;
	if (amount == 0)
	{
		std::cout << YEL "⚙️  " << _name << " tried to repair but gained 0 HP." RESET << std::endl;
		--_energyPoints;
		return;
	}

	--_energyPoints;
	_hitPoints += amount;

	std::cout << CYN "🔧 " << _name
			  << " repairs itself, regaining "
			  << GRN << amount << " HP!" RESET
			  << " (HP: " << YEL << _hitPoints << RESET
			  << ", EP: " << YEL << _energyPoints << RESET << ")" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << RED "🛑 " << _name << " is already dead!" RESET << std::endl;
		return;
	}

	if (amount == 0)
	{
		std::cout << YEL "🧐 " << _name << " takes 0 damage. Nothing happens." RESET << std::endl;
		return;
	}

	std::cout << CYN "💥 " << _name
			  << " takes " << RED << amount << " damage!" RESET
			  << " (HP: " << YEL << _hitPoints << RESET << ")" << std::endl;

	if (_hitPoints <= amount)
	{
		_hitPoints = 0;
		std::cout << RED " (💀 Died)" RESET;
	}
	else
	{
		_hitPoints -= amount;
		std::cout << " (HP: " << YEL << _hitPoints << RESET << ")";
	}
}
