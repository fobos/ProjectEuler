#include <stdlib.h>

unsigned long factorial(unsigned int n)
{
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

