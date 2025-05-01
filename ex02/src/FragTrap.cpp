/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:45:32 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/01 22:12:25 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"

/**
 * Named constructor for FragTrap.
 *
 * Calls the ClapTrap named constructor with the given name.
 * Initializes the hit points to 100, energy points to 50, and attack damage to 20.
 * Prints a message indicating the constructor has been called.
 *
 * @param name The name of the FragTrap.
 */
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << GRN "✅ FragTrap Name constructor called" RESET << std::endl;
}

/**
 * Default constructor for FragTrap.
 *
 * Calls the named constructor with an empty string, effectively creating a
 * FragTrap with no name.
 *
 * Prints a message indicating the constructor has been called.
 */
FragTrap::FragTrap(void) : ClapTrap()
{
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << GRN "✅ FragTrap Default constructor called" RESET << std::endl;
}

/**
 * Copy constructor for FragTrap.
 *
 * Makes a deep copy of the FragTrap at the right-hand side of the operator.
 * All the member variables are copied.
 */
FragTrap::FragTrap(const FragTrap &rhs)
{
	*this = rhs;
	std::cout << YEL "📋 FragTrap Copy constructor called" RESET << std::endl;
}
/**
 * Assignment operator for FragTrap.
 *
 * Makes a deep copy of the FragTrap at the right-hand side of the operator.
 * All the member variables are copied.
 */
FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	if (this != &rhs)
	{
		this->setName(rhs.getName());
		this->setHitPoints(rhs.getHitPoints());
		this->setEnergyPoints(rhs.getEnergyPoints());
		this->setAttackDamage(rhs.getAttackDamage());
	}
	std::cout << YEL "🔁 FragTrap Copy assignment operator called" RESET << std::endl;
	return *this;
}

/**
 * Destructor for FragTrap.
 *
 * Prints a message indicating the destructor has been called with the FragTrap's name.
 */
FragTrap::~FragTrap(void)
{
	std::cout << RED "❌ FragTrap Destructor called for " << this->getName() << RESET << std::endl;
}

/**
 * Requests a high five from the user.
 *
 * Prints a message with the FragTrap's name asking for a high five.
 */
void FragTrap::highFivesGuys(void)
{
	std::cout << GRN "🤚 FragTrap " << this->getName() << " is requesting a high five!" RESET << std::endl;
}
