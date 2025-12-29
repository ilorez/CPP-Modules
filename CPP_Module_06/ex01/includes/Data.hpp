
#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <iostream>

class Data
{
private:
    std::string _name;
    int         _value;

public:
    // Constructors
    Data();
    Data(const std::string &name, int value);
    Data(const Data &other);

    // Destructor
    ~Data();

    // Assignment operator
    Data &operator=(const Data &other);

    // Getters
    const std::string &getName() const;
    int getValue() const;

    // Setter (optional)
    void setName(const std::string &name);
    void setValue(int value);
};

#endif
