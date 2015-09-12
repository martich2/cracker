#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define START 0x0000000000000000L
#define STOP  0xFFFFFFFFFFFFFFFFL
#define PASSWD_SIZE 17
#define BUFFER_SIZE 17*1024

int repeat_filter(char*  passwd, int repeats);
int digit_count_filter(char* passwd, int count);
void i2a(uint64_t number, char *passwd);
int a2i(char letter);
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

    number = START;
    for (; number <= STOP; ++number)
    {
        i2a(number, passwd);

        if (repeat_filter(passwd, 3) && digit_count_filter(passwd, 12))
        {
            printf("%s\n", passwd);
            /*
            memcpy(&passwd_buffer[i++ * PASSWD_SIZE], &passwd, PASSWD_SIZE);

            if (i > 1024)
            {
                i = 0;
                //write buffer to disk
            }
            */
        }
    }
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
    int rep_count = 0;
    int i = 0;

    for (; i < PASSWD_SIZE - 2; i++)
    {
        if (passwd[i] == passwd[i + 1])  
            rep_count++;
        else
            rep_count = 0;

        if (rep_count >= repeats) return 0;
    }
    
    return 1;
}

int digit_count_filter(char* passwd, int count)
{
    int i = 0;
    int sum = 0;
    int result = 0;
    int check_list[16] = {0};

    for (; i < PASSWD_SIZE - 2; i++)
    {
        check_list[a2i(passwd[i])] = 1;
    }

    for (i = 0; i < 16; i++)
        sum += check_list[i];

    if (sum >= count)
        result 1;

    return result;
}
