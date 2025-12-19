/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:18:46 by znajdaou          #+#    #+#             */
/*   Updated: 2025/12/19 23:11:09 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
