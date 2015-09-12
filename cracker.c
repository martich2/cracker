#include <stdio.h>
#include <stdint.h>

#define START 0x0000000000000000L
#define STOP  0x000000000FFFFFFFL

int filter(uint64_t number);
char* itoa(uint64_t number);
int main(int argc, char **argv)
{
    uint64_t number = START;

    for (; number <= STOP; ++number)
    {
        printf("%x\n", number);
    }

    return 0;

}
