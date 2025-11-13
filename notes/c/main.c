#include <stdio.h>

void print(int i);
void print(unsigned int j);

int main(void)
{
    int i = 10;
    unsigned int j = 100;
    
    print(i);
    print(j);
    
    return (0);
}

void print(int i)
{
    printf("Value is: %d\n", i);
}

void print(unsigned int j)
{
    printf("Value is: %u\n", j);
}
