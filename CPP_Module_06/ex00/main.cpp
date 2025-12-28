/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 17:09:42 by znajdaou          #+#    #+#             */
/*   Updated: 2025/12/28 18:33:33 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Container.hpp"
//*
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
        return 1;
    }

    std::string literal = argv[1];

    try
    {
        ScalarConverter::convert(literal);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
// */
/*

static void test(const std::string &literal)
{
    std::cout << "==============================\n";
    std::cout << "Literal: \"" << literal << "\"\n";
    std::cout << "------------------------------\n";
    ScalarConverter::convert(literal);
    std::cout << std::endl;
}

int main(void)
{
    // 🔹 CHAR
    test("a");
    test("z");
    test("0");
    test("!");

    // 🔹 INT
    test("0");
    test("42");
    test("-42");
    test("+42");
    test("2147483647");      // INT_MAX
    test("-2147483648");     // INT_MIN
    test("2147483648");      // overflow

    // 🔹 FLOAT
    test("0.0f");
    test("42.0f");
    test("-42.42f");
    test("+4.2f");
    test("nanf");
    test("+inff");
    test("-inff");

    // 🔹 DOUBLE
    test("0.0");
    test("42.0");
    test("-42.42");
    test("+4.2");
    test("nan");
    test("+inf");
    test("-inf");

    // 🔹 INVALID
    test("hello");
    test("42f");
    test("4.2ff");
    test(".");
    test("..");
    test("");
    test(" ");

    return 0;
}
// */
