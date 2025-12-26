/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 17:09:42 by znajdaou          #+#    #+#             */
/*   Updated: 2025/12/26 18:14:27 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Container.hpp"

int main() {
    Intern someIntern;

    std::cout << "=== Test 1: Create ShrubberyCreationForm ===" << std::endl;
    AForm* f1 = someIntern.makeForm("shrubbery creation", "Home");
    if (f1) {
        std::cout << "Form name: " << f1->getName() << std::endl;
        delete f1;
    }
    std::cout << std::endl;

    std::cout << "=== Test 2: Create RobotomyRequestForm ===" << std::endl;
    AForm* f2 = someIntern.makeForm("robotomy request", "Bender");
    if (f2) {
        std::cout << "Form name: " << f2->getName() << std::endl;
        delete f2;
    }
    std::cout << std::endl;

    std::cout << "=== Test 3: Create PresidentialPardonForm ===" << std::endl;
    AForm* f3 = someIntern.makeForm("presidential pardon", "Alice");
    if (f3) {
        std::cout << "Form name: " << f3->getName() << std::endl;
        delete f3;
    }
    std::cout << std::endl;

    std::cout << "=== Test 4: Invalid form name ===" << std::endl;
    AForm* f4 = someIntern.makeForm("unknown form", "Target");
    if (!f4)
        std::cout << "No form created for unknown name." << std::endl;

    return 0;
}
