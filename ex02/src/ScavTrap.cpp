/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:45:32 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/01 21:30:07 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

/**
 * Named constructor for ScavTrap.
 *
 * Calls the ClapTrap named constructor with the given name.
 * Initializes the hit points to 100, energy points to 50, and attack damage to 20.
 * Prints a message indicating the constructor has been called.
 *
 * @param name The name of the ScavTrap.
 */
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << GRN "✅ ScavTrap Name constructor called" RESET << std::endl;
}

/**
 * Default constructor for ScavTrap.
 *
 * Calls the named constructor with an empty string, effectively creating a
 * ScavTrap with no name.
 *
 * Prints a message indicating the constructor has been called.
 */
ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << GRN "✅ ScavTrap Default constructor called" RESET << std::endl;
}

/**
 * Copy constructor for ScavTrap.
 *
 * Makes a deep copy of the ScavTrap at the right-hand side of the operator.
 * All the member variables are copied.
 */
ScavTrap::ScavTrap(const ScavTrap &rhs)
{
	*this = rhs;
	std::cout << YEL "📋 ScavTrap Copy constructor called" RESET << std::endl;
}
/**
 * Assignment operator for ScavTrap.
 *
 * Makes a deep copy of the ScavTrap at the right-hand side of the operator.
 * All the member variables are copied.
 */
ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	if (this != &rhs)
	{
		this->setName(rhs.getName());
		this->setHitPoints(rhs.getHitPoints());
		this->setEnergyPoints(rhs.getEnergyPoints());
		this->setAttackDamage(rhs.getAttackDamage());
	}
	std::cout << YEL "🔁 ScavTrap Copy assignment operator called" RESET << std::endl;
	return *this;
}

/**
 * Destructor for ScavTrap.
 *
 * Prints a message indicating the destructor has been called with the ScavTrap's name.
 */
ScavTrap::~ScavTrap(void)
{
	std::cout << RED "❌ ScavTrap Destructor called for " << this->getName() << RESET << std::endl;
}

/**
 * Performs an attack on the specified target.
 *
 * Reduces the ScavTrap's energy points by one.
 * If the ScavTrap has no hit points or energy points, the attack is not performed.
 * Prints a message indicating the attack, the target, and the damage dealt.
 *
 * @param target The target of the attack.
 */
void ScavTrap::attack(const std::string &target)
{
	if (!has_points())
		return;
	this->setEnergyPoints(this->getEnergyPoints() - 1);

	std::cout << YEL "🔫 " << this->getName() << " attacks " << target << ", causing "
			  << GRN << this->getAttackDamage() << " points of damage!" RESET << std::endl;
}

/**
 * Puts the ScavTrap into Gate keeper mode.
 *
 * Prints a message indicating the ScavTrap's name and the mode it is now in.
 */
void ScavTrap::guardGate(void)
{
	std::cout << YEL "🛡️  " << this->getName() << " is now in Gate keeper mode." RESET << std::endl;
}
