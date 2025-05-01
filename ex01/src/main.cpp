#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"
#include <iomanip> // for std::setw

// Formatting macros
#define SEPARATOR(txt) std::cout << "\n"                                              \
								 << WHT "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"      \
								 << "🔹 " << txt << "\n"                              \
								 << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" RESET "\n" \
								 << std::endl

#define STATS(ct) std::cout << MAG "📊 "                                         \
							<< std::left << std::setw(10) << ct.getName()        \
							<< " | HP: " << std::setw(3) << ct.getHitPoints()    \
							<< " | EP: " << std::setw(3) << ct.getEnergyPoints() \
							<< " | AD: " << std::setw(3) << ct.getAttackDamage() << RESET << std::endl

// Function declarations
void testClapTraps(void);
void testScavTraps(void);
void printFinalMessage(void);

// Entry point
int main(void)
{
	std::cout << BGRN "\n\n🌟===== 🤖 CLAPTRAP & SCAVTRAP SIMULATION =====🌟\n\n" RESET;

	testClapTraps();
	testScavTraps();
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
	STATS(noName);
	STATS(bob);
	STATS(lisa);
	STATS(dummy);

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
	STATS(noName);
	STATS(bob);
	STATS(lisa);
	STATS(dummy);
	STATS(ghost);
	STATS(shadow);
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
	STATS(scavy);
	STATS(sentinel);

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
	STATS(scavy);
	STATS(sentinel);
	STATS(copyScav);
	STATS(assignedScav);
}

/**
 * @brief Final message indicating simulation end.
 */
void printFinalMessage(void)
{
	std::cout << "\n"
			  << BGRN "🎉✅ Simulation complete! 🎉\n\n" RESET;
}
