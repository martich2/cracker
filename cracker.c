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
void _reverse(char *passwd);

int main(int argc, char **argv)
{
    uint64_t number = START;
    char passwd_buffer[BUFFER_SIZE];
    char passwd[PASSWD_SIZE];
    int i = 0;
    uint64_t test = 0xDEAD1337;

    memset(passwd, '0', PASSWD_SIZE - 1);
    passwd[PASSWD_SIZE - 1] = '\0';

    printf("%d\n", test);
    i2a(test, passwd);
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
    int temp = 0;

    do
    {
        temp = number % 16;
        
        if (temp > 9)
            passwd[i++] = temp - 10 + 'A';
        else
            passwd[i++] = temp + '0';

        number /= 16;
    } while ( number  > 0);

    _reverse(passwd);
}

void _reverse(char *passwd)
{
    int i = 0;
    int j = PASSWD_SIZE - 2; // last char in array, not \0
    char temp;

    for (;;i++, j--)
    {
        if (i >= j) return;
        temp = passwd[i];
        passwd[i] = passwd[j];
        passwd[j] = temp;

    }

}

int repeat_filter(char*  passwd, int repeats)
{
    return 0;
}

int base_count_filter(char* passwd, int count)
{
    return 0;
}
