/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:29:59 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/01 14:29:29 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

#include "../inc/ClapTrap.hpp"

#define SEPARATOR(txt) std::cout << "\n" \
								 << WHT "---- " << txt << " ----" RESET "\n\n"
#define STATS(ct) std::cout << MAG "📊 " << ct.getName()         \
							<< " | HP: " << ct.getHitPoints()    \
							<< " | EP: " << ct.getEnergyPoints() \
							<< " | AD: " << ct.getAttackDamage() << RESET << std::endl

int main(void)
{
	std::cout << BGRN "\n===== 🤖 CLAPTRAP SIMULATION =====\n" RESET << std::endl;

	ClapTrap noName;
	ClapTrap bob("Bob");
	ClapTrap lisa("Lisa");
	ClapTrap dummy("Dummy");

	SEPARATOR("Initial Stats");
	STATS(noName);
	STATS(bob);
	STATS(lisa);
	STATS(dummy);

	SEPARATOR("Attacks");
	noName.attack("Wall");
	bob.attack("Training Bot");
	lisa.attack("Wall");
	dummy.takeDamage(3);

	SEPARATOR("Overkill & Repairs");
	dummy.takeDamage(200); // Should kill dummy
	dummy.beRepaired(50);  // Dead ClapTrap tries to repair
	bob.beRepaired(5);
	lisa.beRepaired(0); // Zero heal attempt

	SEPARATOR("Energy Drain");
	for (int i = 0; i < 10; ++i)
		bob.attack("Goblin"); // Should run out of energy
	bob.beRepaired(3);		  // No EP left

	SEPARATOR("Copy & Assignment");
	ClapTrap ghost(bob); // Copy constructor
	ClapTrap shadow;
	shadow = dummy; // Assignment operator (dummy is dead)

	SEPARATOR("Post-Copy Actions");
	ghost.attack("Echoes");
	shadow.attack("Ghost"); // dead copy, should do nothing

	SEPARATOR("Final Stats");
	STATS(bob);
	STATS(lisa);
	STATS(dummy);
	STATS(ghost);
	STATS(shadow);

	std::cout << "\n"
			  << GRN "✅ Simulation complete!" RESET << std::endl;
	return 0;
}
