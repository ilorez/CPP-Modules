#include <iostream>
#include <string>
#include "./includes/Array.hpp"

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define CYAN  "\033[36m"
#define RESET "\033[0m"

#define OK(msg)   std::cout << GREEN  << "[OK] " << RESET << msg << std::endl
#define FAIL(msg) std::cout << RED    << "[KO] " << RESET << msg << std::endl
#define SECTION(msg) std::cout << std::endl << CYAN << "=== " << msg << " ===" << RESET << std::endl

int main(void)
{
    // ------------------------------------------------------------------ //
    // 1. Default construction — empty array
    // ------------------------------------------------------------------ //
    SECTION("Default construction");
    {
        Array<int> a;
        if (a.size() == 0)
            OK("size() == 0 on empty array");
        else
            FAIL("size() != 0 on empty array");
    }

    // ------------------------------------------------------------------ //
    // 2. Construction with n — default-initialized elements
    // ------------------------------------------------------------------ //
    SECTION("Construction with n elements");
    {
        Array<int> a(5);
        if (a.size() == 5)
            OK("size() == 5");
        else
            FAIL("size() != 5");

        bool zero = true;
        for (unsigned int i = 0; i < a.size(); i++)
        {
            if (a[i] != 0) { zero = false; break; }
        }
        if (zero)
            OK("int elements default-initialized to 0");
        else
            FAIL("int elements NOT default-initialized to 0");

        // same check with a non-trivial type
        Array<std::string> s(3);
        bool empty = true;
        for (unsigned int i = 0; i < s.size(); i++)
            if (s[i] != "") { empty = false; break; }
        if (empty)
            OK("std::string elements default-initialized to \"\"");
        else
            FAIL("std::string elements NOT default-initialized to \"\"");
    }

    // ------------------------------------------------------------------ //
    // 3. Element access and assignment via []
    // ------------------------------------------------------------------ //
    SECTION("Element access via []");
    {
        Array<int> a(5);
        for (unsigned int i = 0; i < a.size(); i++)
            a[i] = (int)(i * 10);

        bool ok = true;
        for (unsigned int i = 0; i < a.size(); i++)
            if (a[i] != (int)(i * 10)) { ok = false; break; }
        if (ok)
            OK("read/write via [] works correctly");
        else
            FAIL("read/write via [] broken");
    }

    // ------------------------------------------------------------------ //
    // 4. Out-of-bounds — exception thrown
    // ------------------------------------------------------------------ //
    SECTION("Out-of-bounds exception");
    {
        Array<int> a(3);

        // index >= size
        try {
            a[3];
            FAIL("no exception on index == size");
        } catch (std::exception &e) {
            OK(std::string("exception caught (index == size): ") + e.what());
        }

        // large index
        try {
            a[100];
            FAIL("no exception on index 100");
        } catch (std::exception &e) {
            OK(std::string("exception caught (index 100): ") + e.what());
        }

        // empty array
        Array<int> empty;
        try {
            empty[0];
            FAIL("no exception on empty array access");
        } catch (std::exception &e) {
            OK(std::string("exception caught (empty array): ") + e.what());
        }
    }

    // ------------------------------------------------------------------ //
    // 5. Copy construction — deep copy
    // ------------------------------------------------------------------ //
    SECTION("Copy construction (deep copy)");
    {
        Array<int> a(4);
        for (unsigned int i = 0; i < a.size(); i++)
            a[i] = (int)i;

        Array<int> b(a);

        // mutate original — copy must not change
        for (unsigned int i = 0; i < a.size(); i++)
            a[i] = 42;

        bool independent = true;
        for (unsigned int i = 0; i < b.size(); i++)
            if (b[i] != (int)i) { independent = false; break; }

        if (independent)
            OK("copy is independent from original after copy-construction");
        else
            FAIL("copy shares data with original (shallow copy bug)");

        if (b.size() == 4)
            OK("copy has correct size");
        else
            FAIL("copy has wrong size");
    }

    // ------------------------------------------------------------------ //
    // 6. Assignment operator — deep copy
    // ------------------------------------------------------------------ //
    SECTION("Assignment operator (deep copy)");
    {
        Array<int> a(3);
        a[0] = 1; a[1] = 2; a[2] = 3;

        Array<int> b(5);   // different size
        b = a;

        // mutate copy — original must not change
        b[0] = 99;

        if (a[0] == 1)
            OK("original unchanged after modifying assigned copy");
        else
            FAIL("original changed — assignment is shallow");

        if (b.size() == 3)
            OK("assigned array has correct size");
        else
            FAIL("assigned array has wrong size");
    }

    // ------------------------------------------------------------------ //
    // 7. Self-assignment
    // ------------------------------------------------------------------ //
    SECTION("Self-assignment");
    {
        Array<int> a(3);
        a[0] = 7; a[1] = 8; a[2] = 9;
        a = a;
        if (a[0] == 7 && a[1] == 8 && a[2] == 9 && a.size() == 3)
            OK("self-assignment leaves array intact");
        else
            FAIL("self-assignment corrupted the array");
    }

    // ------------------------------------------------------------------ //
    // 8. size() is const
    // ------------------------------------------------------------------ //
    SECTION("size() is const");
    {
        const Array<int> a(4);
        if (a.size() == 4)
            OK("size() callable on const instance");
        else
            FAIL("size() not callable on const instance");
    }

    // ------------------------------------------------------------------ //
    // 9. Works with multiple types
    // ------------------------------------------------------------------ //
    SECTION("Template with multiple types");
    {
        Array<double> d(2);
        d[0] = 3.14; d[1] = 2.71;
        if (d[0] == 3.14 && d[1] == 2.71)
            OK("double array works");
        else
            FAIL("double array broken");

        Array<char> c(3);
        c[0] = 'a'; c[1] = 'b'; c[2] = 'c';
        if (c[0] == 'a' && c[1] == 'b' && c[2] == 'c')
            OK("char array works");
        else
            FAIL("char array broken");
    }

    std::cout << std::endl;
    return 0;
}
