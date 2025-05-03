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
#include "../inc/DiamondTrap.hpp"

// ─────────────────────────────────────────────
//                Format Macros
// ─────────────────────────────────────────────
#define SEPARATOR(txt) std::cout << "\n"                                              \
                                 << WHT "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"      \
                                 << "🔹 " << txt << "\n"                              \
                                 << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" RESET "\n" \
                                 << std::endl

// ─────────────────────────────────────────────
//              Function Prototypes
// ─────────────────────────────────────────────
void testClapTraps();
void testScavTraps();
void testFragTraps();
void testDiamondTraps();
void printFinalMessage();

// ─────────────────────────────────────────────
//                  Entry Point
// ─────────────────────────────────────────────
int main()
{
	std::cout << BGRN "\n\n🌟===== 🤖 CLAPTRAP & SCAVTRAP SIMULATION =====🌟\n\n" RESET;

	testClapTraps();
	testScavTraps();
	testFragTraps();
	testDiamondTraps();
	printFinalMessage();

	return 0;
}

// ─────────────────────────────────────────────
//              ClapTrap Demonstration
// ─────────────────────────────────────────────
void testClapTraps()
{
	SEPARATOR("📦 ClapTrap Construction");
	ClapTrap noName, bob("Bob"), lisa("Lisa"), dummy("Dummy");

	SEPARATOR("📊 Initial ClapTrap Stats");
	std::cout << noName << bob << lisa << dummy << std::endl;

	SEPARATOR("⚔️ ClapTrap Attacks");
	noName.attack("Wall");
	bob.attack("Training Bot");
	lisa.attack("Wall");
	dummy.takeDamage(3);

	SEPARATOR("💀 Overkill & Repairs");
	dummy.takeDamage(200);
	dummy.beRepaired(50);
	bob.beRepaired(5);
	lisa.beRepaired(0);

	SEPARATOR("⚡ Energy Drain Test");
	for (int i = 0; i < 10; ++i) bob.attack("Goblin");
	bob.attack("Orc");
	bob.beRepaired(3);

	SEPARATOR("🔁 Copy & Assignment");
	ClapTrap ghost(bob), shadow;
	shadow = dummy;

	SEPARATOR("🧪 Post-Copy Actions");
	ghost.attack("Echoes");
	shadow.attack("Ghost");

	SEPARATOR("📈 Final ClapTrap Stats");
	std::cout << noName << bob << lisa << dummy << ghost << shadow << std::endl;
}

// ─────────────────────────────────────────────
//              ScavTrap Demonstration
// ─────────────────────────────────────────────
void testScavTraps()
{
	SEPARATOR("🛠️ ScavTrap Construction");
	ScavTrap scavy("Scavy"), sentinel("Sentinel");

	SEPARATOR("📊 Initial ScavTrap Stats");
	std::cout << scavy << sentinel << std::endl;

	SEPARATOR("⚔️ ScavTrap Actions");
	scavy.attack("Intruder");
	sentinel.takeDamage(scavy.getAttackDamage());
	sentinel.guardGate();
	sentinel.beRepaired(20);
	scavy.takeDamage(50);

	SEPARATOR("🔁 Copy & Assignment - ScavTrap");
	ScavTrap copyScav(scavy), assignedScav;
	assignedScav = sentinel;

	copyScav.attack("Mirror Bot");
	assignedScav.guardGate();

	SEPARATOR("📈 Final ScavTrap Stats");
	std::cout << scavy << sentinel << copyScav << assignedScav << std::endl;
}

// ─────────────────────────────────────────────
//              FragTrap Demonstration
// ─────────────────────────────────────────────
void testFragTraps()
{
	SEPARATOR("🛠️ FragTrap Construction");
	FragTrap frag1("Frag1"), frag2("Frag2"), dummyFrag("DummyFrag");

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
	dummyFrag.takeDamage(85);
	dummyFrag.highFivesGuys();

	SEPARATOR("⚡ Energy Stress Test");
	for (int i = 0; i < 5; i++) frag2.attack("Target");
	frag2.beRepaired(50);

	SEPARATOR("🔁 FragTrap Cloning");
	FragTrap clone(frag1), assigned;
	assigned = frag2;

	SEPARATOR("🎭 Clone Actions");
	clone.attack("Clone Target");
	assigned.highFivesGuys();

	SEPARATOR("📈 Final FragTrap Stats");
	std::cout << frag1 << frag2 << dummyFrag << clone << assigned << std::endl;
}

// ─────────────────────────────────────────────
//             DiamondTrap Demonstration
// ─────────────────────────────────────────────
void testDiamondTraps()
{
	SEPARATOR("💎 DiamondTrap Masterclass");
	DiamondTrap gem("Gemini"), ghost;

	SEPARATOR("🔍 Initial Verification");
	std::cout << gem << ghost << std::endl;
	std::cout << CYN "Gemini's ClapTrap name: " << gem.ClapTrap::getName() << RESET "\n"
	          << CYN "Gemini's Diamond name: " YEL << gem.getName() << RESET << std::endl;

	SEPARATOR("⚔️ Multi-Class Combat");
	gem.attack("Raider");
	gem.takeDamage(20);
	gem.beRepaired(15);
	gem.guardGate();
	gem.highFivesGuys();

	SEPARATOR("⚡ Energy Stress Test");
	for (int i = 0; i < 5; i++) gem.attack("Training Bot");
	gem.attack("Overkill");

	SEPARATOR("💥 Damage Verification");
	gem.takeDamage(95);
	gem.beRepaired(10);
	gem.takeDamage(150);
	gem.beRepaired(5);

	SEPARATOR("🧬 Copy Mechanics");
	DiamondTrap twin(gem), mirror;
	mirror = gem;

	twin.whoAmI();
	std::cout << CYN "Copied HP: " YEL << twin.getHitPoints()
	          << CYN " | EP: " YEL << twin.getEnergyPoints() << RESET << std::endl;

	mirror.attack("Clone Target");
	mirror.whoAmI();

	SEPARATOR("💀 Post-Mortem Checks");
	ghost.takeDamage(300);
	ghost.attack("Phantom");
	ghost.beRepaired(10);
	ghost.whoAmI();

	SEPARATOR("📈 Final Status Report");
	std::cout << gem << ghost << twin << mirror << std::endl;

	SEPARATOR("🔗 Name Inheritance in Copies");
	std::cout << CYN "Original ClapName: " GRN << gem.ClapTrap::getName() << RESET "\n"
	          << CYN "Copy ClapName: " GRN << twin.ClapTrap::getName() << RESET "\n"
	          << CYN "Assignment ClapName: " GRN << mirror.ClapTrap::getName() << RESET << std::endl;
}

// ─────────────────────────────────────────────
//                  Final Message
// ─────────────────────────────────────────────
void printFinalMessage()
{
	std::cout << "\n" << BGRN "🎉✅ Simulation complete! 🎉\n\n" RESET;
}
