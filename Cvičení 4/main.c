#include <stdio.h>
#include <memory.h>

long addIntegerWithReturn(long a, int b)
{
    return a + (long)b;
}

void addIntegerWithPointers(long *a, int b)
{
    *a += (long)b;
}

void printFirstBytesOfLongAsInt(long *value)
{
    int retypedValue = (int)*value;
    printf("4 bytes:\t%04x\n", retypedValue);
}

//Literally nejde, protože compiler to zomptimalizuje
void swapLongHalves(long *a)
{
    printf("%x\n", *a);

    long test = (*a>>8);
    long test2 = (*a<<8);

    printf("%x\n", test);
    printf("%x\n", test2);
}

int main()
{
    long input = 199999;
    printf("Original Value:\t%ld\n", input);

    addIntegerWithPointers(&input, 5);
    printf("addInteger:\t%ld\n", input);

    printFirstBytesOfLongAsInt(&input);
    swapLongHalves(&input);
}