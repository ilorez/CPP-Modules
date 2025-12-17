/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:18:46 by znajdaou          #+#    #+#             */
/*   Updated: 2025/12/17 16:56:18 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Point.hpp"

/*
int main(void)
{
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    std::cout << bsp(a, b, c, Point(2, 2)) << std::endl;   // 1
    std::cout << bsp(a, b, c, Point(20, 20)) << std::endl; // 0
    std::cout << bsp(a, b, c, Point(5, 0)) << std::endl;   // 0
    std::cout << bsp(a, b, c, Point(0, 0)) << std::endl;   // 0
    std::cout << bsp(a, b, c, Point(10.1f, 0.1f)) << std::endl; // 0
    std::cout << bsp(a, b, c, Point(0.1f, 0.1f)) << std::endl;  // 1
    std::cout << bsp(a, c, b, Point(2, 2)) << std::endl;   // 1
}

*/


int main(void)
{
    // Scalene triangle (not right, not axis-aligned)
    Point a(-5, -2);
    Point b(3, 7);
    Point c(8, -4);

    // 1️⃣ Clearly inside
    Point p1(2, 1);
    std::cout << "Inside (2,1): " << bsp(a, b, c, p1) << std::endl; // 1

    // 2️⃣ Clearly outside (left side)
    Point p2(-10, 0);
    std::cout << "Outside (-10,0): " << bsp(a, b, c, p2) << std::endl; // 0

    // 3️⃣ Outside (above)
    Point p3(4, 10);
    std::cout << "Outside (4,10): " << bsp(a, b, c, p3) << std::endl; // 0

    // 4️⃣ On edge AB
    Point p4(-1, 2.5f);
    std::cout << "On edge AB: " << bsp(a, b, c, p4) << std::endl; // 0

    // 5️⃣ On edge BC
    Point p5(5.5f, 1.5f);
    std::cout << "On edge BC: " << bsp(a, b, c, p5) << std::endl; // 0

    // 6️⃣ On vertex C
    Point p6(8, -4);
    std::cout << "On vertex C: " << bsp(a, b, c, p6) << std::endl; // 0

    // 7️⃣ Very close inside (precision)
    Point p7(2.0001f, 1.0001f);
    std::cout << "Very close inside: " << bsp(a, b, c, p7) << std::endl; // 1

    // 8️⃣ Very close outside
    Point p8(8.0001f, -4.0001f);
    std::cout << "Very close outside: " << bsp(a, b, c, p8) << std::endl; // 0

    // 9️⃣ Reversed triangle order
    Point p9(2, 1);
    std::cout << "Reversed order: " << bsp(b, a, c, p9) << std::endl; // 1

    return 0;
}

