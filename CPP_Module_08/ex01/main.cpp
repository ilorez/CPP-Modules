#include "includes/Span.hpp"
#include "iostream"
/*
int main()
{
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;
  return 0;
}
//*/


#include <vector>

static void printTitle(const std::string& title)
{
    std::cout << "\n========== " << title
              << " ==========\n";
}

int main()
{
    // --------------------------------------------------
    // Subject test
    // --------------------------------------------------
    printTitle("Subject Test");

    try
    {
        Span sp(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: "
                  << sp.shortestSpan() << std::endl;

        std::cout << "Longest span : "
                  << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    // --------------------------------------------------
    // Empty Span
    // --------------------------------------------------
    printTitle("Empty Span");

    try
    {
        Span sp(5);

        std::cout << sp.shortestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: "
                  << e.what() << std::endl;
    }

    // --------------------------------------------------
    // One element only
    // --------------------------------------------------
    printTitle("One Element");

    try
    {
        Span sp(5);

        sp.addNumber(42);

        std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: "
                  << e.what() << std::endl;
    }

    // --------------------------------------------------
    // Full Span
    // --------------------------------------------------
    printTitle("Full Span");

    try
    {
        Span sp(3);

        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);

        sp.addNumber(4); // should throw
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: "
                  << e.what() << std::endl;
    }

    // --------------------------------------------------
    // Duplicates
    // --------------------------------------------------
    printTitle("Duplicates");

    try
    {
        Span sp(5);

        sp.addNumber(10);
        sp.addNumber(10);
        sp.addNumber(20);

        std::cout << "Shortest span: "
                  << sp.shortestSpan() << std::endl;

        std::cout << "Longest span : "
                  << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    // --------------------------------------------------
    // Negative numbers
    // --------------------------------------------------
    printTitle("Negative Numbers");

    try
    {
        Span sp(5);

        sp.addNumber(-100);
        sp.addNumber(-50);
        sp.addNumber(25);
        sp.addNumber(75);

        std::cout << "Shortest span: "
                  << sp.shortestSpan() << std::endl;

        std::cout << "Longest span : "
                  << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    // --------------------------------------------------
    // Range insertion
    // --------------------------------------------------
    printTitle("Range Insertion");

    try
    {
        std::vector<int> values;

        values.push_back(5);
        values.push_back(10);
        values.push_back(15);
        values.push_back(20);
        values.push_back(25);

        Span sp(10);

        sp.fillRange(values.begin(), values.end());

        std::cout << "Shortest span: "
                  << sp.shortestSpan() << std::endl;

        std::cout << "Longest span : "
                  << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    // --------------------------------------------------
    // Range overflow
    // --------------------------------------------------
    printTitle("Range Overflow");

    try
    {
        std::vector<int> values(10, 42);

        Span sp(5);

        sp.fillRange(values.begin(), values.end());
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: "
                  << e.what() << std::endl;
    }

    // --------------------------------------------------
    // 10000 numbers test
    // --------------------------------------------------
    printTitle("10000 Numbers");

    try
    {
        Span sp(10000);

        for (int i = 0; i < 10000; ++i)
            sp.addNumber(i);

        std::cout << "Shortest span: "
                  << sp.shortestSpan() << std::endl;

        std::cout << "Longest span : "
                  << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
