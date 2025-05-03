/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:45:32 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/01 22:12:25 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

/**
 * @brief Parameterized constructor for DiamondTrap.
 * 
 * This constructor initializes the base classes ClapTrap, ScavTrap, and FragTrap
 * with the provided name. The ClapTrap name is modified to include the "_clap_name"
 * suffix. It also sets initial hit points, energy points, and attack damage.
 * 
 * @param name The name to assign to the DiamondTrap (without the "_clap_name" suffix).
 */
DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name")
	, ScavTrap(name)
	, FragTrap(name)
	, _name(name)
{
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(30);
	std::cout << GRN "✅ DiamondTrap Name constructor called" RESET << std::endl;
}

/**
 * @brief Default constructor for DiamondTrap.
 * 
 * Initializes the base classes with default names and sets default
 * hit points, energy points, and attack damage.
 */
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

/**
 * @brief Copy constructor for DiamondTrap.
 * 
 * Creates a new DiamondTrap by copying values from another instance,
 * including all base class data and the DiamondTrap-specific name.
 * 
 * @param rhs Reference to the DiamondTrap object to copy.
 */
DiamondTrap::DiamondTrap(const DiamondTrap &rhs)
	: ClapTrap(rhs)
	, ScavTrap(rhs)
	, FragTrap(rhs)
	, _name(rhs._name)
{
	std::cout << YEL "📋 DiamondTrap Copy constructor called" RESET << std::endl;
}

/**
 * @brief Copy assignment operator.
 * 
 * Assigns the values from another DiamondTrap to this instance,
 * including base class attributes and the DiamondTrap name.
 * 
 * @param rhs Reference to the DiamondTrap to copy from.
 * @return Reference to the assigned DiamondTrap instance.
 */
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

/**
 * @brief Destructor for DiamondTrap.
 * 
 * Prints a message when the destructor is called.
 * Destroys the object and its base class components.
 */
DiamondTrap::~DiamondTrap(void)
{
	std::cout << RED "❌ DiamondTrap Destructor called for " << this->_name << RESET << std::endl;
}

/**
 * @brief Get the name of the DiamondTrap (not the ClapTrap name).
 * 
 * @return std::string The DiamondTrap's own name.
 */
std::string DiamondTrap::getName(void) const
{
	return this->_name;
}

/**
 * @brief Print both the DiamondTrap's name and its inherited ClapTrap name.
 * 
 * Useful for verifying correct initialization and inheritance of names.
 */
void DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name: " << this->_name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::getName() << std::endl;
}
