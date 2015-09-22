#include <string.h>
#include <stdlib.h>
#include "cracker.h"

int main(int argc, char **argv)
{
    uint64_t number = START;
    char passwd[PASSWD_SIZE];
    int digits = 8;

    if (argc >= 2)
        digits = atoi(argv[1]);

    memset(passwd, '0', PASSWD_SIZE - 1);
    passwd[PASSWD_SIZE - 1] = '\0';

    for (; number <= STOP; ++number)
    {
        i2a(number, passwd);
        if (incremental_filter(passwd, 2))
        {
            if (repeat_filter(passwd, 3))
            {
                if (min_digit_count_filter(passwd, digits))
                {
                    printf("%s\n", passwd);
                }
            }
        }
        memset(passwd, '0', PASSWD_SIZE - 1);
    }

    return 0;
}
