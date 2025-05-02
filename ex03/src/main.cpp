#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"
#include "../inc/FragTrap.hpp"
#include "../inc/DiamondTrap.hpp"
#include <iomanip>

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
void testDiamondTraps(void);
void printFinalMessage(void);

// Entry point
int main(void)
{
	std::cout << BGRN "\n\n🌟===== 🤖 CLAPTRAP & SCAVTRAP SIMULATION =====🌟\n\n" RESET;

	testClapTraps();
	testScavTraps();
	testFragTraps();
	testDiamondTraps();
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

void testDiamondTraps()
{
	SEPARATOR("💎 DiamondTrap Masterclass");
	DiamondTrap gem("Gemini");
	DiamondTrap ghost;

	// Initial verification
	SEPARATOR("🔍 Initial Verification");
	std::cout << gem << ghost << std::endl;
	std::cout << CYN "Gemini's ClapTrap name: " << gem.ClapTrap::getName() << RESET "\n"
			  << CYN "Gemini's Diamond name: " YEL << gem.getName() << RESET << std::endl;

	SEPARATOR("⚔️ Multi-Class Combat");
	gem.attack("Raider");             // ScavTrap attack
	gem.takeDamage(20);               // Base ClapTrap function
	gem.beRepaired(15);
	gem.guardGate();                  // ScavTrap exclusive
	gem.highFivesGuys();              // FragTrap exclusive

	// Energy depletion test
	SEPARATOR("⚡ Energy Stress Test");
	for (int i = 0; i < 5; i++) {
		gem.attack("Training Bot");
	}
	gem.attack("Overkill");  // Should fail (0 energy)

	// Damage verification
	SEPARATOR("💥 Damage Verification");
	gem.takeDamage(95);  // 100HP - 95 = 5HP left
	gem.beRepaired(10);  // Should work (5 + 10 = 15HP)
	gem.takeDamage(150); // Should die
	gem.beRepaired(5);   // Dead repair attempt

	SEPARATOR("🧬 Copy Mechanics");
	DiamondTrap twin(gem);           // Copy constructor
	DiamondTrap mirror;
	mirror = gem;                    // Assignment

	// Verify copy integrity
	twin.whoAmI();
	std::cout << CYN "Copied HP: " YEL << twin.getHitPoints()
			  << CYN " | EP: " YEL << twin.getEnergyPoints() << RESET << std::endl;

	// Test copied objects
	mirror.attack("Clone Target");
	mirror.whoAmI();

	SEPARATOR("💀 Post-Mortem Checks");
	ghost.takeDamage(300);           // Instant death
	ghost.attack("Phantom");         // Should fail
	ghost.beRepaired(10);            // Should fail
	ghost.whoAmI();                  // Should show names despite being dead

	SEPARATOR("📈 Final Status Report");
	std::cout << gem << ghost << twin << mirror << std::endl;

	// Explicit name check in copies
	SEPARATOR("🔗 Name Inheritance in Copies");
	std::cout << CYN "Original ClapName: " GRN << gem.ClapTrap::getName() << RESET "\n"
			  << CYN "Copy ClapName: " GRN << twin.ClapTrap::getName() << RESET "\n"
			  << CYN "Assignment ClapName: " GRN << mirror.ClapTrap::getName() << RESET << std::endl;
}

/**
 * @brief Final message indicating simulation end.
 */
void printFinalMessage(void)
{
	std::cout << "\n"
			  << BGRN "🎉✅ Simulation complete! 🎉\n\n" RESET;
}
