#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define START 0x0000000000000000L
#define STOP  0x000FFFFFFFFFFFFFL
#define PASSWD_SIZE 17
#define BUFFER_SIZE 17*1024

int repeat_filter(char*  passwd, int repeats);
int base_count_filter(char* passwd, int count);
void i2a(uint64_t number, char *passwd);
void _reverse(char *str);

int main(int argc, char **argv)
{
    uint64_t number = START;
    char passwd_buffer[BUFFER_SIZE];
    char passwd[PASSWD_SIZE];
    int i = 0;

    memset(passwd, '0', PASSWD_SIZE - 1);
    passwd[PASSWD_SIZE - 1] = '\0';


    printf("%s\n", passwd);
    i2a(123456790123456, passwd);
    printf("%s\n", passwd);

    number = START;
/*
    for (; number <= STOP; ++number)
    {
        i2a(number, passwd);
        if (repeat_filter(passwd, 3) && base_count_filter(passwd, 12))
        {
            printf("%x\n", number);
            memcpy(&passwd_buffer[i++ * PASSWD_SIZE], &passwd, PASSWD_SIZE);

            if (i > 1024)
            {
                i = 0;
                //write buffer to disk
            }
        }
    }
*/
    // write buffer to disk

    return 0;
}

void i2a(uint64_t number, char *passwd)
{
    int i = 0;

    do
    {
        passwd[i++] = number % 10 + '0';
        number /= 10;
    } while ( number  > 0);

    //_reverse(passwd);
}

void _reverse(char *str)
{
}

int repeat_filter(char*  passwd, int repeats)
{
    return 0;
}

int base_count_filter(char* passwd, int count)
{
    return 0;
}
