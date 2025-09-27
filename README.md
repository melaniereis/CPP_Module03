# ⚔️ CPP Module 03 - Inheritance

<div align="center">

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![42 School](https://img.shields.io/badge/42-School-000000?style=for-the-badge&logo=42&logoColor=white)
![Module](https://img.shields.io/badge/Module-03-blue?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Completed-success?style=for-the-badge)

*Mastering Inheritance Hierarchies and Virtual Functions*

</div>

## 📖 Overview

**CPP Module 03** introduces the fundamental concept of **inheritance** in object-oriented programming. Through the exciting world of ClapTrap robots, you'll explore single inheritance, multiple inheritance, virtual functions, and the infamous diamond problem. This module builds a complete inheritance hierarchy from basic robots to advanced diamond-shaped inheritance patterns.

### 🎯 Learning Objectives

- Master single inheritance and base-derived relationships
- Understand virtual functions and polymorphic behavior
- Implement multiple inheritance and resolve ambiguity
- Solve the diamond problem with virtual inheritance
- Practice proper constructor/destructor chaining
- Explore method overriding and function hiding

## 💡 Key Concepts Introduced

- **Single Inheritance**: Base and derived class relationships
- **Virtual Functions**: Dynamic method resolution and polymorphism
- **Multiple Inheritance**: Deriving from multiple base classes
- **Diamond Problem**: Inheritance ambiguity and its resolution
- **Virtual Inheritance**: Solving diamond inheritance issues
- **Constructor Chaining**: Proper initialization order in inheritance
- **Method Overriding**: Redefining inherited behavior

## 🤖 The ClapTrap Universe

All exercises revolve around robot classes with combat-like functionality:
- **Attack**: Deal damage to targets
- **Take Damage**: Receive and handle incoming damage
- **Repair**: Restore hit points using energy
- **Energy Management**: Limited actions based on energy points

## 🚀 Exercises

### 🔰 Exercise 00: Aaaaand... OPEN!
**Files**: `ClapTrap.cpp`, `ClapTrap.hpp`, `main.cpp`

Foundation class implementing a basic combat robot, demonstrating:
- Complete class design with Orthodox Canonical Form
- Basic robot functionality and state management
- Resource management (hit points, energy points)
- Action validation and state checking

**ClapTrap Class**:
```cpp
class ClapTrap {
public:
    ClapTrap(void);                              // Default constructor
    ClapTrap(std::string name);                  // Name constructor
    ClapTrap(const ClapTrap &rhs);               // Copy constructor
    ClapTrap &operator=(const ClapTrap &rhs);    // Copy assignment
    ~ClapTrap(void);                             // Destructor

    void attack(const std::string &target);      // Attack action
    void takeDamage(unsigned int amount);        // Take damage
    void beRepaired(unsigned int amount);        // Repair action

    // Getters
    std::string getName(void) const;
    unsigned int getHitPoints(void) const;
    unsigned int getEnergyPoints(void) const;
    unsigned int getAttackDamage(void) const;

    bool has_points(void) const;                 // Check if can act

private:
    std::string _name;           // Robot name
    unsigned int _hitPoints;     // Health (10)
    unsigned int _energyPoints;  // Action energy (10)
    unsigned int _attackDamage;  // Attack damage (0)
};
```

**Robot Stats**:
- **Hit Points**: 10
- **Energy Points**: 10
- **Attack Damage**: 0

**Behavior**:
```cpp
void ClapTrap::attack(const std::string &target) {
    if (!has_points()) {
        std::cout << "ClapTrap " << _name << " has no energy or hit points!" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " attacks " << target
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
}
```

**Usage Example**:
```cpp
ClapTrap robot("R2D2");
robot.attack("Death Star");
robot.takeDamage(5);
robot.beRepaired(3);
```

**Key Learning Points**:
- Foundation class design principles
- State management and validation
- Resource-based action system
- Orthodox Canonical Form implementation

---

### 🛡️ Exercise 01: Serena, My Love!
**Files**: `ClapTrap.cpp`, `ClapTrap.hpp`, `ScavTrap.cpp`, `ScavTrap.hpp`, `main.cpp`

Introduction to single inheritance with enhanced combat capabilities, showcasing:
- Public inheritance from base class
- Constructor chaining and initialization
- Virtual function overriding
- Specialized behavior implementation

**ScavTrap Class** (inherits from ClapTrap):
```cpp
class ScavTrap : public ClapTrap {
public:
    ScavTrap(void);                              // Default constructor
    ScavTrap(std::string name);                  // Name constructor
    ScavTrap(const ScavTrap &rhs);               // Copy constructor
    ScavTrap &operator=(const ScavTrap &rhs);    // Copy assignment
    ~ScavTrap(void);                             // Destructor

    virtual void attack(const std::string &target);  // Overridden attack
    void guardGate(void);                        // Special ability
};
```

**Enhanced Stats**:
- **Hit Points**: 100 (inherited and modified)
- **Energy Points**: 50 (inherited and modified)
- **Attack Damage**: 20 (inherited and modified)

**Constructor Chaining**:
```cpp
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "🤖 ScavTrap Name constructor called" << std::endl;
}
```

**Specialized Methods**:
```cpp
void ScavTrap::attack(const std::string &target) {
    if (!has_points()) {
        std::cout << "ScavTrap " << _name << " has no energy or hit points!" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "ScavTrap " << _name << " attacks " << target
              << " with enhanced weaponry, causing " << _attackDamage
              << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(void) {
    std::cout << "ScavTrap " << _name << " has entered Gate keeper mode!" << std::endl;
}
```

**Usage Example**:
```cpp
ScavTrap guardian("Guardian");
guardian.attack("Intruder");       // Uses overridden attack
guardian.guardGate();              // Special ScavTrap ability
```

**Key Learning Points**:
- Single inheritance implementation
- Constructor/destructor chaining
- Virtual function overriding
- Access to protected/public base members
- Specialized behavior while maintaining base functionality

---

### 💥 Exercise 02: Repetitive Work
**Files**: `ClapTrap.cpp`, `ClapTrap.hpp`, `ScavTrap.cpp`, `ScavTrap.hpp`, `FragTrap.cpp`, `FragTrap.hpp`, `main.cpp`

Second inheritance branch creating parallel derived classes, demonstrating:
- Multiple inheritance branches from same base
- Different specialization paths
- Virtual function implementation variations
- Polymorphic behavior through base pointers

**FragTrap Class** (also inherits from ClapTrap):
```cpp
class FragTrap : public ClapTrap {
public:
    FragTrap(void);                              // Default constructor
    FragTrap(std::string name);                  // Name constructor
    FragTrap(const FragTrap &rhs);               // Copy constructor
    FragTrap &operator=(const FragTrap &rhs);    // Copy assignment
    ~FragTrap(void);                             // Destructor

    void highFivesGuys(void);                    // Special ability
};
```

**FragTrap Stats**:
- **Hit Points**: 100
- **Energy Points**: 100
- **Attack Damage**: 30

**Constructor Implementation**:
```cpp
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "🤖 FragTrap Name constructor called" << std::endl;
}
```

**Special Ability**:
```cpp
void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << _name << " requests high fives! ✋" << std::endl;
}
```

**Inheritance Tree**:
```
       ClapTrap
      /         \
  ScavTrap    FragTrap
```

**Polymorphic Usage**:
```cpp
ClapTrap* robots[3];
robots[0] = new ClapTrap("Basic");
robots[1] = new ScavTrap("Guard");
robots[2] = new FragTrap("Heavy");

for (int i = 0; i < 3; i++) {
    robots[i]->attack("Enemy");  // Calls appropriate attack method
}
```

**Key Learning Points**:
- Parallel inheritance branches
- Different specialization approaches
- Polymorphic behavior through base pointers
- Virtual function table concepts
- Memory management in inheritance hierarchies

---

### 💎 Exercise 03: Now It's Weird!
**Files**: `ClapTrap.cpp`, `ClapTrap.hpp`, `ScavTrap.cpp`, `ScavTrap.hpp`, `FragTrap.cpp`, `FragTrap.hpp`, `DiamondTrap.cpp`, `DiamondTrap.hpp`, `main.cpp`

Advanced multiple inheritance and diamond problem resolution, showcasing:
- Multiple inheritance from two derived classes
- Diamond problem identification and solution
- Virtual inheritance implementation
- Ambiguity resolution and method selection

**DiamondTrap Class** (inherits from both ScavTrap and FragTrap):
```cpp
class DiamondTrap : public ScavTrap, public FragTrap {
public:
    DiamondTrap(void);                           // Default constructor
    DiamondTrap(std::string name);               // Name constructor
    DiamondTrap(const DiamondTrap &rhs);         // Copy constructor
    DiamondTrap &operator=(const DiamondTrap &rhs); // Copy assignment
    ~DiamondTrap(void);                          // Destructor

    using ScavTrap::attack;                      // Resolve attack ambiguity
    virtual std::string getName(void) const;    // Override name getter
    void whoAmI(void);                           // Special diagnostic

private:
    std::string _name;                           // DiamondTrap's own name
};
```

**Diamond Inheritance Problem**:
```
        ClapTrap
       /         \
  ScavTrap    FragTrap
       \         /
     DiamondTrap
```

**The Diamond Problem**:
- DiamondTrap inherits from both ScavTrap and FragTrap
- Both ScavTrap and FragTrap inherit from ClapTrap
- DiamondTrap gets two copies of ClapTrap's members
- Ambiguity: Which ClapTrap's methods to use?

**Solution - Virtual Inheritance**:
```cpp
// Modified inheritance declarations
class ScavTrap : virtual public ClapTrap { ... };
class FragTrap : virtual public ClapTrap { ... };
class DiamondTrap : public ScavTrap, public FragTrap { ... };
```

**Attribute Combination**:
DiamondTrap combines the best of both worlds:
- **Hit Points**: 100 (from FragTrap)
- **Energy Points**: 50 (from ScavTrap)
- **Attack Damage**: 30 (from FragTrap)
- **Attack Method**: ScavTrap's attack (explicitly chosen)

**Complex Constructor**:
```cpp
DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {
    _hitPoints = FragTrap::_hitPoints;      // 100
    _energyPoints = ScavTrap::_energyPoints; // 50
    _attackDamage = FragTrap::_attackDamage; // 30
    std::cout << "💎 DiamondTrap Name constructor called" << std::endl;
}
```

**Special Methods**:
```cpp
void DiamondTrap::whoAmI(void) {
    std::cout << "DiamondTrap name: " << _name << std::endl;
    std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}

std::string DiamondTrap::getName(void) const {
    return _name;  // Returns DiamondTrap's own name, not ClapTrap's
}
```

**Usage Example**:
```cpp
DiamondTrap diamond("Shiny");
diamond.attack("Target");        // Uses ScavTrap's attack (via using declaration)
diamond.guardGate();             // ScavTrap ability
diamond.highFivesGuys();         // FragTrap ability
diamond.whoAmI();                // DiamondTrap diagnostic
```

**Key Learning Points**:
- Multiple inheritance complexities
- Diamond problem identification and resolution
- Virtual inheritance mechanics
- Ambiguity resolution techniques
- Constructor initialization order in complex hierarchies
- Using declarations for method selection

## 🛠️ Compilation

Each exercise includes a Makefile with standard targets:

```bash
# Compile the program
make

# Clean object files
make clean

# Clean everything
make fclean

# Recompile
make re
```

**Compilation flags**:
```bash
c++ -Wall -Wextra -Werror -std=c++98
```

## 🎮 How to Run

### Exercise 00 - Aaaaand... OPEN!
```bash
cd ex00
make
./claptrap
```

### Exercise 01 - Serena, My Love!
```bash
cd ex01
make
./scavtrap
```

### Exercise 02 - Repetitive Work
```bash
cd ex02
make
./fragtrap
```

### Exercise 03 - Now It's Weird!
```bash
cd ex03
make
./diamondtrap
```

## 🧪 Testing Examples

### Basic Inheritance Test
```cpp
// Test constructor/destructor chaining
{
    ScavTrap robot("Guardian");
    robot.attack("Enemy");
    robot.guardGate();
} // Destructor chain: ~ScavTrap -> ~ClapTrap
```

### Polymorphism Test
```cpp
ClapTrap* robot = new ScavTrap("Poly");
robot->attack("Target");  // Calls ScavTrap::attack if virtual
delete robot;             // Proper cleanup if destructors are virtual
```

### Diamond Inheritance Test
```cpp
DiamondTrap diamond("Complex");
std::cout << "DiamondTrap name: " << diamond.getName() << std::endl;
std::cout << "Hit points: " << diamond.getHitPoints() << std::endl;    // 100
std::cout << "Energy: " << diamond.getEnergyPoints() << std::endl;     // 50
std::cout << "Attack damage: " << diamond.getAttackDamage() << std::endl; // 30

diamond.attack("Enemy");     // ScavTrap's attack method
diamond.guardGate();         // ScavTrap ability
diamond.highFivesGuys();     // FragTrap ability
diamond.whoAmI();            // DiamondTrap diagnostic
```

## 🏗️ Project Structure

```
CPP_Module03/
├── README.md
├── ex00/                    # Aaaaand... OPEN!
│   ├── Makefile
│   ├── inc/
│   │   ├── ansi.h
│   │   └── ClapTrap.hpp
│   └── src/
│       ├── ClapTrap.cpp
│       └── main.cpp
├── ex01/                    # Serena, My Love!
│   ├── Makefile
│   ├── inc/
│   │   ├── ansi.h
│   │   ├── ClapTrap.hpp
│   │   └── ScavTrap.hpp
│   └── src/
│       ├── ClapTrap.cpp
│       ├── ScavTrap.cpp
│       └── main.cpp
├── ex02/                    # Repetitive Work
│   ├── Makefile
│   ├── inc/
│   │   ├── ansi.h
│   │   ├── ClapTrap.hpp
│   │   ├── ScavTrap.hpp
│   │   └── FragTrap.hpp
│   └── src/
│       ├── ClapTrap.cpp
│       ├── ScavTrap.cpp
│       ├── FragTrap.cpp
│       └── main.cpp
└── ex03/                    # Now It's Weird!
    ├── Makefile
    ├── inc/
    │   ├── ansi.h
    │   ├── ClapTrap.hpp
    │   ├── ScavTrap.hpp
    │   ├── FragTrap.hpp
    │   └── DiamondTrap.hpp
    └── src/
        ├── ClapTrap.cpp
        ├── ScavTrap.cpp
        ├── FragTrap.cpp
        ├── DiamondTrap.cpp
        └── main.cpp
```

## 💡 Key Takeaways

1. **Inheritance Hierarchy**: Building logical class relationships
2. **Constructor Chaining**: Proper initialization order and dependency
3. **Virtual Functions**: Enabling polymorphic behavior
4. **Multiple Inheritance**: Power and complexity of inheriting from multiple bases
5. **Diamond Problem**: Understanding and resolving inheritance ambiguities
6. **Virtual Inheritance**: Solving diamond problems with shared base classes
7. **Method Resolution**: Controlling which methods are called in complex hierarchies

## 🎯 Skills Developed

- ✅ Single inheritance design and implementation
- ✅ Virtual function declaration and overriding
- ✅ Constructor/destructor chaining mastery
- ✅ Multiple inheritance complexity management
- ✅ Diamond problem identification and resolution
- ✅ Virtual inheritance implementation
- ✅ Polymorphic design patterns
- ✅ Ambiguity resolution techniques

## ⚠️ Common Pitfalls & Solutions

1. **Forgetting Virtual Destructors**: Always make destructors virtual in base classes
2. **Constructor Order**: Base constructors are called before derived ones
3. **Diamond Problem**: Use virtual inheritance when multiple paths to same base
4. **Method Ambiguity**: Use scope resolution or using declarations to clarify
5. **Protected vs Private**: Protected allows access from derived classes
6. **Slicing**: Avoid passing derived objects by value to base parameters

## 🔗 Inheritance Best Practices

### When to Use Inheritance
- **Is-a Relationship**: Derived class "is a" type of base class
- **Behavioral Extension**: Adding functionality to existing classes
- **Polymorphic Interfaces**: Need different behaviors through same interface

### Virtual Function Guidelines
- Make destructors virtual in base classes
- Make functions virtual if they might be overridden
- Use pure virtual functions for abstract interfaces
- Consider performance implications of virtual calls

### Multiple Inheritance Caution
- Use sparingly and only when clearly beneficial
- Prefer composition over multiple inheritance when possible
- Always consider virtual inheritance for diamond scenarios
- Document inheritance relationships clearly

## 🔗 Next Steps

After mastering Module 03, you'll be ready to tackle:
- **Module 04**: Subtype polymorphism and abstract classes
- **Module 05**: Exception handling mechanisms
- **Module 06**: C++ casts and type conversions

---

<div align="center">

*"Inheritance is not just about reusing code, it's about expressing relationships."*

**Module 03 Complete** ✨ | **Previous**: [← Module 02](../CPP_Module02/README.md) | **Next**: [Module 04 →](../CPP_Module04/README.md)

</div>
