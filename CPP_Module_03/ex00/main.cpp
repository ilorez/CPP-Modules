/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:18:46 by znajdaou          #+#    #+#             */
/*   Updated: 2025/12/19 18:38:26 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    std::cout << "--- CONSTRUCTORS ---" << std::endl;
    ClapTrap clap("CLP-42");
    ClapTrap trap("TRP-99");
    ClapTrap anonymous; // Testing default constructor

    std::cout << "\n--- BASIC ACTIONS ---" << std::endl;
    clap.attack("a random fly");
    trap.takeDamage(5);
    trap.beRepaired(3);

    std::cout << "\n--- ENERGY DEPLETION TEST ---" << std::endl;
    // ClapTrap has 10 EP. Let's use them all.
    for (int i = 0; i < 10; ++i) {
        std::cout << "[" << i << "] ";
        clap.attack("the wall");
    }
    // This 11th action should fail
    std::cout << "Attempting 11th action:" << std::endl;
    clap.beRepaired(5);

    std::cout << "\n--- DEATH TEST ---" << std::endl;
    // trap currently has 8 HP (10 - 5 + 3).
    trap.takeDamage(10); // Should 'kill' it
    trap.attack("revenge"); // Should fail because it's dead
    trap.beRepaired(10);    // Should fail because it's dead

    std::cout << "\n--- CANONICAL FORM TEST ---" << std::endl;
    {
        ClapTrap original("Original");
        ClapTrap copy(original); // Copy Constructor
        ClapTrap assignment("Temporary");
        
        assignment = original; // Assignment Operator
        assignment.attack("an enemy");
    } // Destructors for the local scope will fire here

    std::cout << "\n--- END OF TESTS ---" << std::endl;
    return 0;
}
