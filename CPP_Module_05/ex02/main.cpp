/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 17:09:42 by znajdaou          #+#    #+#             */
/*   Updated: 2025/12/25 19:15:04 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Container.hpp"

//* -------- tests

int main()
{
    std::cout << "========== CREATE BUREAUCRATS ==========\n";
    Bureaucrat boss("Boss", 1);
    Bureaucrat intern("Intern", 150);

    std::cout << boss << std::endl;
    std::cout << intern << std::endl;

    std::cout << "\n========== CREATE FORMS ==========\n";
    AForm* shrub = new ShrubberyCreationForm("home");
    //AForm* robo  = new RobotomyRequestForm("Bender");
    //AForm* pardon = new PresidentialPardonForm("Arthur Dent");

    std::cout << *shrub << std::endl;
    //std::cout << *robo << std::endl;
    //std::cout << *pardon << std::endl;

    std::cout << "\n========== EXECUTE UNSIGNED FORM ==========\n";
    boss.executeForm(*shrub);

    std::cout << "\n========== SIGN FORMS ==========\n";
    intern.signForm(*shrub);   // should fail
    boss.signForm(*shrub);     // should succeed
    //boss.signForm(*robo);
    //boss.signForm(*pardon);

    std::cout << "\n========== EXECUTE WITH LOW GRADE ==========\n";
    intern.executeForm(*shrub); // should fail

    std::cout << "\n========== EXECUTE SUCCESS ==========\n";
    boss.executeForm(*shrub);   // creates file
    //boss.executeForm(*robo);    // random result
    //boss.executeForm(*pardon);  // pardon message

    std::cout << "\n========== DELETE FORMS ==========\n";
    delete shrub;
    //delete robo;
    //delete pardon;

    std::cout << "\n========== END OF TEST ==========\n";
    return 0;
}

// */
