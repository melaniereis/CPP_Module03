/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:45:32 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/01 22:12:25 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"


DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name+"_clap_name")
	, ScavTrap(name)
	, FragTrap(name)
	, _name(name)
{
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(30);
	std::cout << GRN "✅ DiamondTrap Name constructor called" RESET << std::endl;
}


DiamondTrap::DiamondTrap(void)
	: ClapTrap("Default_clap_name")
	, ScavTrap("Default")
	, FragTrap("Default")
	, _name("Default")
{
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(30);
	std::cout << GRN "✅ DiamondTrap Default constructor called" RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &rhs)
	: ClapTrap(rhs)
	, ScavTrap(rhs)
	, FragTrap(rhs)
	, _name(rhs._name)
{
	std::cout << YEL "📋 DiamondTrap Copy constructor called" RESET << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
		_name = rhs._name;
		setName(_name + "_clap_name");
	}
	std::cout << YEL "🔁 DiamondTrap Copy assignment operator called" RESET << std::endl;
	return *this;
}


DiamondTrap::~DiamondTrap(void)
{
	std::cout << RED "❌ DiamondTrap Destructor called for " << this->_name << RESET << std::endl;
}

std::string DiamondTrap::getName(void) const
{
	return this->_name;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name: " << this->_name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::getName() << std::endl;
}
