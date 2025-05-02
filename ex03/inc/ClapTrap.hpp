/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:31:03 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/02 21:14:19 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include "ansi.h"
#include <iostream>
#include <iomanip>

class ClapTrap
{
public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &rhs);
	ClapTrap &operator=(const ClapTrap &rhs);
	virtual ~ClapTrap(void);

	virtual void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string getName(void) const;
	unsigned int getHitPoints(void) const;
	unsigned int getEnergyPoints(void) const;
	unsigned int getAttackDamage(void) const;

	void setName(std::string name);
	void setHitPoints(unsigned int amount);
	void setEnergyPoints(unsigned int amount);
	void setAttackDamage(unsigned int amount);

	bool has_points(void) const;

private:
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;
};

std::ostream &operator<<(std::ostream &out, ClapTrap const &rhs);

#endif
