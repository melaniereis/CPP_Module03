/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:29:59 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/01 21:48:39 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

#define SEPARATOR(txt) std::cout << "\n" \
								 << WHT "🔹 " << txt << RESET "\n"

/**
 * @brief Full simulation of ClapTrap behavior including:
 *        creation, combat, death handling, energy drain, copy and assignment.
 */
int main(void)
{
	std::cout << BGRN "\n===== 🤖 CLAPTRAP SIMULATION =====\n" RESET << std::endl;

	ClapTrap noName;
	ClapTrap bob("Bob");
	ClapTrap lisa("Lisa");
	ClapTrap dummy("Dummy");

	SEPARATOR("Initial Stats");
	std::cout << noName << bob << lisa << dummy << std::endl;

	SEPARATOR("⚔️  Attacks");
	noName.attack("Wall");
	bob.attack("Training Bot");
	lisa.attack("Wall");
	dummy.takeDamage(3);

	SEPARATOR("💀 Overkill & Repairs");
	dummy.takeDamage(200); // Dummy should die here
	dummy.beRepaired(50);  // Attempt to repair a dead ClapTrap
	bob.beRepaired(5);
	lisa.beRepaired(0); // Attempt to repair with 0 HP gain

	SEPARATOR("⚡ Energy Drain");
	for (int i = 0; i < 10; ++i)
		bob.attack("Goblin"); // Should exhaust Bob's energy
	bob.attack("Orc");		  // One more attack to confirm no EP
	bob.beRepaired(3);		  // Attempt to repair with no EP

	SEPARATOR("🌀 Copy & Assignment");
	ClapTrap ghost(bob); // Copy of Bob
	ClapTrap shadow;
	shadow = dummy; // Dummy is dead, assign to shadow

	SEPARATOR("🧪 Post-Copy Actions");
	ghost.attack("Echoes");
	shadow.attack("Ghost"); // Should do nothing (dead)

	SEPARATOR("📈 Final Stats");
	std::cout << noName << bob << lisa << dummy << ghost << shadow << std::endl;

	std::cout << "\n"
			  << GRN "✅ Simulation complete!" RESET << std::endl;
	return 0;
}
