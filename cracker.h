#ifndef CRACKER_H
#define CRACKER_H

#include <stdint.h>

#define START1 0x10BE27ED6F87EC28L
#define START2 0xEFB8DB41C4D1FD62L
#define START 0x0000000000000000L
#define STOP  0xFFFFFFFFFFFFFFFFL
#define PASSWD_SIZE 17

// no repeated digits past repeats count
int repeat_filter(char*  passwd, int repeats);

// minimum number of unique digits
int min_digit_count_filter(char* passwd, int count);

// no incremental digits beyound count, 12345DEADBEEF
int incremental_filter(char* passwd, int count);

int min_num_let_filter(char* passwd, int count);

// minimum count of letters in a row
int min_let_row_filter(char* passwd, int count);

// minimum cout of numbers in a row
int min_num_row_filter(char* passwd, int count);

// convert an number to a character array with trailing 0 chars
void i2a(uint64_t number, char *passwd);

// convert a single letter to a single digit number
int a2i(char letter);

// reverse a string.
void _reverse(char *passwd);

#endif
