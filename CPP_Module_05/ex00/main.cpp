/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 17:09:42 by znajdaou          #+#    #+#             */
/*   Updated: 2025/12/24 20:08:18 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Container.hpp"

//* -------- tests
int main()
{
    std::cout << "=== Valid Bureaucrat creation ===" << std::endl;
    try {
        Bureaucrat bob("Bob", 42);
        std::cout << bob << std::endl;

        std::cout << "\n=== Increment grade ===" << std::endl;
        bob.increment();
        std::cout << bob << std::endl;

        std::cout << "\n=== Decrement grade ===" << std::endl;
        bob.decrement();
        std::cout << bob << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Invalid Bureaucrat creation (too high) ===" << std::endl;
    try {
        Bureaucrat tooHigh("Alice", 0);
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Invalid Bureaucrat creation (too low) ===" << std::endl;
    try {
        Bureaucrat tooLow("Charlie", 151);
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Increment/Decrement exceptions ===" << std::endl;
    try {
        Bureaucrat top("Top", 1);
        top.increment(); // should throw
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat bottom("Bottom", 150);
        bottom.decrement(); // should throw
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Copy constructor test ===" << std::endl;
    Bureaucrat original("Original", 75);
    Bureaucrat copy(original); // copy constructor
    std::cout << copy << std::endl;

    std::cout << "\n=== Assignment operator test ===" << std::endl;
    Bureaucrat assign("Assign", 100);
    assign = original; // only grade will be copied
    std::cout << assign << std::endl;

    return 0;
}
// */
