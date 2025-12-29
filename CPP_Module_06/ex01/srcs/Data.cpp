#include "../includes/Data.hpp"

// ================= Constructors =================
Data::Data() : _name("default"), _value(0) {}

Data::Data(const std::string &name, int value) : _name(name), _value(value) {}

Data::Data(const Data &other) : _name(other._name), _value(other._value) {}

// ================= Destructor =================
Data::~Data() {}

// ================= Assignment Operator =================
Data &Data::operator=(const Data &other)
{
    if (this != &other)
    {
        _name = other._name;
        _value = other._value;
    }
    return *this;
}

// ================= Getters =================
const std::string &Data::getName() const { return _name; }
int Data::getValue() const { return _value; }

// ================= Setters (optional) =================
void Data::setName(const std::string &name) { _name = name; }
void Data::setValue(int value) { _value = value; }
