/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:18:46 by znajdaou          #+#    #+#             */
/*   Updated: 2025/12/20 16:38:26 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    std::cout << "===== 1. THE DIAMOND CONSTRUCTION =====" << std::endl;
    {
        // LOOK CLOSELY AT THE OUTPUT:
        // ClapTrap should only be constructed ONCE.
        // If it constructs twice, your virtual inheritance is broken.
        DiamondTrap diamond("D14-M0ND");
        std::cout << "\n--- Testing Attributes (Expectations: HP 100, EP 50, AD 30) ---" << std::endl;
        
        // These calls verify it can perform actions from all parents
        diamond.whoAmI();           // DiamondTrap unique
        diamond.attack("a thief");  // Must be ScavTrap's attack
        diamond.guardGate();        // From ScavTrap
        diamond.highFivesGuys();     // From FragTrap

        std::cout << "\n--- Testing Damage/Repair ---" << std::endl;
        diamond.takeDamage(40);
        diamond.beRepaired(20);
        
        std::cout << "\n--- Destruction Sequence ---" << std::endl;
    } // ClapTrap must be destroyed only ONCE at the very end.

    std::cout << "\n===== 2. NAME SHADOWING TEST =====" << std::endl;
    DiamondTrap obscure("Shadow");
    obscure.whoAmI(); 
    // You should see two different names: 
    // One is "Shadow", the other is "Shadow_clap_name"

    std::cout << "\n===== 3. CANONICAL FORM =====" << std::endl;
    DiamondTrap original("Alpha");
    std::cout << "---------" << std::endl;
    DiamondTrap copy(original);
    std::cout << "---------" << std::endl;
    DiamondTrap assigned("Beta");
    assigned = copy;
    assigned.whoAmI();

    std::cout << "\n===== END OF TESTS =====" << std::endl;
    return 0;
}
/*
#include "FragTrap.hpp"
int main()
{
    std::cout << "===== 1. FRAGTRAP CONSTRUCTION =====" << std::endl;
    {
        // Should show ClapTrap constructor then FragTrap constructor
        FragTrap frag("FR4G-TP");
        std::cout << "FragTrap is ready!" << std::endl;
    } // Should show FragTrap destructor then ClapTrap destructor

    std::cout << "\n===== 2. THE FRAGTRAP EXPERIENCE =====" << std::endl;
    FragTrap frag("Handsome-Frag");

    // FragTrap has 30 Attack Damage
    frag.attack("a generic bandit");
    
    // FragTrap has 100 HP
    frag.takeDamage(50);
    frag.beRepaired(25);

    std::cout << "\n===== 3. SPECIAL CAPACITY: HIGH FIVES =====" << std::endl;
    // This is the unique requirement for Ex02
    frag.highFivesGuys();

    std::cout << "\n===== 4. EXTREME ENERGY TEST =====" << std::endl;
    // FragTrap has 100 EP. Let's see if it can do a lot of actions.
    for (int i = 0; i < 5; i++) {
        frag.attack("the air");
    }
    std::cout << "FragTrap still has " << "tons of energy left (started with 100)." << std::endl;

    std::cout << "\n===== 5. DEATH & REPAIR LIMITS =====" << std::endl;
    frag.takeDamage(150); // Overkill
    frag.attack("the afterlife"); // Should fail
    frag.highFivesGuys(); // Even in death, its can do high five because subject tell nothing about that 

    std::cout << "\n===== 6. CANONICAL FORM (FR4G) =====" << std::endl;
    FragTrap original("OG_Frag");
    FragTrap copy(original);
    FragTrap assigned("Temporary");
    assigned = original;

    std::cout << "\n===== 7. END OF TESTS =====" << std::endl;
    return 0;
}
#include "ScavTrap.hpp"

int main()
{
    std::cout << "===== 1. CONSTRUCTOR/DESTRUCTOR CHAINING =====" << std::endl;
    {
        // Watch the output: ClapTrap should be built first, then ScavTrap.
        ScavTrap scav("SC4V-TP");
        std::cout << "ScavTrap " << " created." << std::endl;
    } // Watch the output: ScavTrap should be destroyed first, then ClapTrap.

    std::cout << "\n===== 2. ATTRIBUTE & ATTACK OVERRIDE =====" << std::endl;
    ScavTrap scav("Serena");
    ClapTrap clap("Basic-Clap");

    // ScavTrap attack should look different and use its higher Attack Damage (20)
    scav.attack("a target");
    clap.attack("the same target");

    std::cout << "\n===== 3. SPECIAL CAPACITY: GUARD GATE =====" << std::endl;
    scav.guardGate();

    std::cout << "\n===== 4. STAMINA TEST (EP management) =====" << std::endl;
    // ScavTrap has 50 EP, ClapTrap has only 10.
    // We can test if ScavTrap survived more actions than a ClapTrap would.
    for (int i = 0; i < 5; i++) {
        scav.beRepaired(10);
    }
    std::cout << "ScavTrap still has plenty of energy." << std::endl;

    std::cout << "\n===== 5. LETHAL DAMAGE TEST =====" << std::endl;
    // ScavTrap has 100 HP. It should survive a hit of 50.
    scav.takeDamage(50);
    scav.beRepaired(20);
    // It should 'die' after taking too much damage
    scav.takeDamage(100);
    scav.attack("the void"); // Should fail if HP is 0

    std::cout << "\n===== 6. CANONICAL FORM (SC4V) =====" << std::endl;
    ScavTrap original("Original_Scav");
    ScavTrap copy(original);
    ScavTrap assigned("Temp");
    assigned = copy;

    std::cout << "\n===== 7. END OF TESTS =====" << std::endl;
    return 0;
}
*/
