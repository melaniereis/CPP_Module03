/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:45:32 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/03 09:11:22 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"
#include "../inc/FragTrap.hpp"

// Formatting macros
#define SEPARATOR(txt) std::cout << "\n"                                              \
								 << WHT "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"      \
								 << "🔹 " << txt << "\n"                              \
								 << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" RESET "\n" \
								 << std::endl

// Function declarations
void testClapTraps(void);
void testScavTraps(void);
void testFragTraps(void);
void printFinalMessage(void);

// Entry point
int main(void)
{
	std::cout << BGRN "\n\n🌟===== 🤖 CLAPTRAP & SCAVTRAP SIMULATION =====🌟\n\n" RESET;

	testClapTraps();
	testScavTraps();
	testFragTraps();
	printFinalMessage();

	return 0;
}

/**
 * @brief Simulates ClapTrap behavior: construction, combat, repairs,
 *        energy depletion, copying, and assignment.
 */
void testClapTraps(void)
{
	SEPARATOR("📦 ClapTrap Construction");

	ClapTrap noName;
	ClapTrap bob("Bob");
	ClapTrap lisa("Lisa");
	ClapTrap dummy("Dummy");

	SEPARATOR("📊 Initial ClapTrap Stats");
	std::cout << noName << bob << lisa << dummy << std::endl;


	SEPARATOR("⚔️ ClapTrap Attacks");
	noName.attack("Wall");
	bob.attack("Training Bot");
	lisa.attack("Wall");
	dummy.takeDamage(3);

	SEPARATOR("💀 Overkill & Repairs");
	dummy.takeDamage(200); // dummy should die
	dummy.beRepaired(50);  // dead ClapTrap tries to heal
	bob.beRepaired(5);
	lisa.beRepaired(0); // 0 heal attempt

	SEPARATOR("⚡ Energy Drain Test");
	for (int i = 0; i < 10; ++i)
		bob.attack("Goblin"); // drains energy
	bob.attack("Orc");		  // no EP left
	bob.beRepaired(3);		  // attempt repair with 0 EP

	SEPARATOR("🔁 Copy & Assignment");
	ClapTrap ghost(bob); // copy constructor
	ClapTrap shadow;
	shadow = dummy; // assignment of a dead object

	SEPARATOR("🧪 Post-Copy Actions");
	ghost.attack("Echoes");
	shadow.attack("Ghost"); // should fail (dead)

	SEPARATOR("📈 Final ClapTrap Stats");
	std::cout << noName << bob << lisa << dummy << ghost << shadow << std::endl;
}

/**
 * @brief Simulates ScavTrap behavior: combat, repairs, guard mode, copying,
 *        and assignment.
 */
void testScavTraps(void)
{
	SEPARATOR("🛠️ ScavTrap Construction");

	ScavTrap scavy("Scavy");
	ScavTrap sentinel("Sentinel");

	SEPARATOR("📊 Initial ScavTrap Stats");
	std::cout << scavy << sentinel << std::endl;

	SEPARATOR("⚔️ ScavTrap Actions");
	scavy.attack("Intruder");
	sentinel.takeDamage(scavy.getAttackDamage());
	sentinel.guardGate();
	sentinel.beRepaired(20);
	scavy.takeDamage(50);

	SEPARATOR("🔁 Copy & Assignment - ScavTrap");
	ScavTrap copyScav(scavy); // copy constructor
	ScavTrap assignedScav;
	assignedScav = sentinel; // assignment operator

	copyScav.attack("Mirror Bot");
	assignedScav.guardGate();

	SEPARATOR("📈 Final ScavTrap Stats");
	std::cout << scavy << sentinel << copyScav << assignedScav << std::endl;
}

/**
 * @brief Simulates FragTrap behavior: combat, high fives, energy drain, cloning,
 *        and assignment.
 */
void testFragTraps(void)
{
	SEPARATOR("🛠️ FragTrap Construction");
	FragTrap frag1("Frag1");
	FragTrap frag2("Frag2");
	FragTrap dummyFrag("DummyFrag");

	SEPARATOR("📊 Initial FragTrap Stats");
	std::cout << frag1 << frag2 << dummyFrag << std::endl;

	SEPARATOR("⚔️ FragTrap Combat");
	frag1.attack("Bandit");
	frag2.attack("Raider");
	dummyFrag.takeDamage(25);
	dummyFrag.beRepaired(10);

	SEPARATOR("🤝 High Five Requests");
	frag1.highFivesGuys();
	frag2.highFivesGuys();
	dummyFrag.takeDamage(85); // Reduce to 0 HP
	dummyFrag.highFivesGuys(); // Should still work

	SEPARATOR("⚡ Energy Stress Test");
	frag2.setEnergyPoints(5);
	std::cout << frag2 << std::endl;
	for (int i = 0; i < 5; i++) {
		frag2.attack("Target");
	}
	frag2.beRepaired(50); // Should fail after energy drain

	SEPARATOR("🔁 FragTrap Cloning");
	FragTrap clone(frag1);
	FragTrap assigned;
	assigned = frag2;

	SEPARATOR("🎭 Clone Actions");
	clone.attack("Clone Target");
	assigned.highFivesGuys();

	SEPARATOR("📈 Final FragTrap Stats");
	std::cout << frag1 << frag2 << dummyFrag << clone << assigned << std::endl;
}

/**
 * @brief Final message indicating simulation end.
 */
void printFinalMessage(void)
{
	std::cout << "\n"
			  << BGRN "🎉✅ Simulation complete! 🎉\n\n" RESET;
}
