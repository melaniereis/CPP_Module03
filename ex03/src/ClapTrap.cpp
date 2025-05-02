/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:30:12 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/02 16:01:52 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

/**
 * Default constructor for ClapTrap.
 *
 * Sets name to empty string, hitPoints to 10, energyPoints to 10 and attackDamage to 0.
 */
ClapTrap::ClapTrap(void) : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << GRN "✅ ClapTrap Default constructor called" RESET << std::endl;
}

/**
 * Constructor for ClapTrap, taking a std::string name as argument.
 *
 * This constructor will set the ClapTrap's name to the given name, and hitPoints,
 * energyPoints and attackDamage to 10, 10 and 0 respectively.
 */
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << GRN "✅ ClapTrap Name constructor called" RESET << std::endl;
}

/**
 * Copy constructor for ClapTrap.
 *
 * Makes a deep copy of the ClapTrap at the right-hand side of the operator.
 * All the member variables are copied.
 */
ClapTrap::ClapTrap(const ClapTrap &rhs)
{
	*this = rhs;
	std::cout << YEL "📋 ClapTrap Copy constructor called" RESET << std::endl;
}
/**
 * Assignment operator for ClapTrap.
 *
 * Makes a deep copy of the ClapTrap at the right-hand side of the operator.
 * All the member variables are copied.
 */
ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_attackDamage = rhs.getAttackDamage();
	}
	std::cout << YEL "🔁 ClapTrap Copy assignment operator called" RESET << std::endl;
	return *this;
}

/**
 * Destructor for ClapTrap.
 *
 * Prints a message indicating the destructor has been called with the ClapTrap's name.
 */
ClapTrap::~ClapTrap(void)
{
	std::cout << RED "❌ ClapTrap Destructor called for " << _name << RESET << std::endl;
}

/**
 * Getter for the ClapTrap's name.
 *
 * Returns the ClapTrap's name, which is a std::string.
 */
std::string ClapTrap::getName(void) const
{
	return _name;
}

/**
 * Getter for the ClapTrap's hit points.
 *
 * Returns the ClapTrap's current hit points, which is an unsigned int.
 */
unsigned int ClapTrap::getHitPoints(void) const
{
	return _hitPoints;
}

/**
 * Getter for the ClapTrap's energy points.
 *
 * Returns the ClapTrap's current energy points, which is an unsigned int.
 */
unsigned int ClapTrap::getEnergyPoints(void) const
{
	return _energyPoints;
}

/**
 * Getter for the ClapTrap's attack damage.
 *
 * Returns the ClapTrap's current attack damage, which is an unsigned int.
 */
unsigned int ClapTrap::getAttackDamage(void) const
{
	return _attackDamage;
}

/**
 * Setter for the ClapTrap's name.
 *
 * Sets the ClapTrap's name to the given std::string.
 */
void ClapTrap::setName(std::string name)
{
	this->_name = name;
}

/**
 * Setter for the ClapTrap's hit points.
 *
 * Sets the ClapTrap's hit points to the given unsigned int.
 */
void ClapTrap::setHitPoints(unsigned int hitPoints)
{
	this->_hitPoints = hitPoints;
}

/**
 * Setter for the ClapTrap's energy points.
 *
 * Sets the ClapTrap's energy points to the given unsigned int.
 */
void ClapTrap::setEnergyPoints(unsigned int energyPoints)
{
	this->_energyPoints = energyPoints;
}

/**
 * Setter for the ClapTrap's attack damage.
 *
 * Sets the ClapTrap's attack damage to the given unsigned int.
 */
void ClapTrap::setAttackDamage(unsigned int attackDamage)
{
	this->_attackDamage = attackDamage;
}

/**
 * Checks if the ClapTrap has any hit points or energy points left.
 *
 * Returns false if either hit points or energy points are 0.
 * Prints a message indicating the lack of points.
 * Otherwise, returns true.
 */
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

/**
 * Performs an attack on the specified target.
 *
 * Reduces the ClapTrap's energy points by one.
 * If the ClapTrap has no hit points or energy points, the attack is not performed.
 * Prints a message indicating the attack, the target, and the damage dealt.
 *
 * @param target The target of the attack.
 */
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

/**
 * Repairs the ClapTrap by increasing its hit points.
 *
 * If the ClapTrap has no hit points or energy points, the repair is not performed.
 * Reduces the ClapTrap's energy points by one.
 * If the repair amount is zero, a message is printed indicating no gain in HP,
 * and energy points are still reduced.
 * Prints a message indicating the amount of hit points regained.
 *
 * @param amount The amount of hit points to be regained.
 */
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

/**
 * Inflicts damage on the ClapTrap, reducing its hit points.
 *
 * If the ClapTrap is already dead (hit points are 0), a message is printed
 * and no further action is taken. If the damage amount is 0, a message is
 * printed indicating no change, and no further action is taken.
 * Otherwise, the specified amount of damage is subtracted from the ClapTrap's
 * hit points. A message is printed showing the damage taken and the updated
 * hit points. If the damage reduces the hit points to zero or below, the
 * ClapTrap is considered dead, and a corresponding message is printed.
 *
 * @param amount The amount of damage to inflict on the ClapTrap.
 */

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
		std::cout << RED " (💀 Died)" RESET << std::endl;
	}
	else
	{
		_hitPoints -= amount;
		std::cout << " (HP: " << YEL << _hitPoints << RESET << ")";
	}
}

/**
 * Overloaded insertion operator for ClapTrap.
 *
 * Prints a message showing the name, hit points, energy points, and attack
 * damage of the ClapTrap.
 */
std::ostream& operator<<(std::ostream& out, const ClapTrap& rhs)
{
	out << MAG "📊 "
		<< std::left << std::setw(10) << rhs.getName()
		<< " | HP: " << std::setw(3) << rhs.getHitPoints()
		<< " | EP: " << std::setw(3) << rhs.getEnergyPoints()
		<< " | AD: " << std::setw(3) << rhs.getAttackDamage() << RESET << std::endl;
	return out;
}
