#include "cracker.h"

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

int min_digit_count_filter(char* passwd, int count)
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
        result = 1;

    return result;
}

int incremental_filter(char* passwd, int count)
{
    int i = 0;
    int sum = 0;
    int result = 1;

    for(; i < PASSWD_SIZE - 3; i++)
    {
        if (a2i(passwd[i]) + 1 == a2i(passwd[i + 1]))
            sum++;
    }

    if (sum >= count) result = 0;

    return result;
}

int min_num_let_filter(char* passwd, int count);
int min_let_row_filter(char* passwd, int count);

int a2i(char letter)
{
    int result;

    if ((letter >= '0') && (letter <= '9' ))
        result = (int)letter - '0';

    if ((letter >= 'A') && (letter <= 'F'))
        result = (int)letter - 'A' + 10;

    return result;
}
