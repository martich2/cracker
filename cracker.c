#include <stdio.h>
#include <stdint.h>

#define START 0x0000000000000000L
#define STOP  0x000000000FFFFFFFL

int repeat_filter(uint64_t number, int repeats);
int base_count_filter(uint64_t number, int count);
void i2a(uint64_t number, char *str);
void _reverse(char *str);

int main(int argc, char **argv)
{
    char passwd_buffer[4*1024];

    uint64_t number = START;

    for (; number <= STOP; ++number)
    {
        printf("%x\n", number);
    }

    return 0;

}
