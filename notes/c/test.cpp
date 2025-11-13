#include <iostream>

void print(int i);
void print(unsigned int j);

int main(void)
{
    int i = 10;
    unsigned int j = 100;
    
    print(i);
    print(j);
    print(i, j);
    
    return (0);
}

void print(int i)
{
    std::cout << "Value is: " << i << std::endl;
}

void print(unsigned int j)
{
    std::cout << "Value is: " << j << std::endl;
}

void print(int i, unsigned int j)
{
    std::cout << "Values are: " << i << " and " << j << std::endl;
}
