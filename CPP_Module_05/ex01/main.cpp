/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 17:09:42 by znajdaou          #+#    #+#             */
/*   Updated: 2025/12/25 15:08:48 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Container.hpp"

//* -------- tests

int main()
{
    std::cout << "========== TEST 1: VALID FORM CREATION ==========\n";
    try
    {
        Form f1("Tax Form", 50, 25);
        std::cout << f1 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n========== TEST 2: INVALID FORM (GRADE TOO HIGH) ==========\n";
    try
    {
        Form f2("Secret Form", 0, 10); // invalid
        std::cout << f2 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n========== TEST 3: INVALID FORM (GRADE TOO LOW) ==========\n";
    try
    {
        Form f3("Lost Form", 200, 10); // invalid
        std::cout << f3 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n========== TEST 4: SIGN FORM (SUCCESS) ==========\n";
    try
    {
        Bureaucrat b1("Alice", 20);
        Form f4("Contract", 50, 10);

        std::cout << b1 << std::endl;
        std::cout << f4 << std::endl;

        b1.signForm(f4);

        std::cout << f4 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n========== TEST 5: SIGN FORM (FAIL - GRADE TOO LOW) ==========\n";
    try
    {
        Bureaucrat b2("Bob", 100);
        Form f5("VIP Form", 50, 10);

        std::cout << b2 << std::endl;
        b2.signForm(f5);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n========== TEST 6: SIGN ALREADY SIGNED FORM ==========\n";
    try
    {
        Bureaucrat b3("Charlie", 1);
        Form f6("Top Secret", 10, 5);

        b3.signForm(f6);
        b3.signForm(f6); // sign again

        std::cout << f6 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n========== END OF TESTS ==========\n";
    return 0;
}
// */
