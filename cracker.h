#ifndef CRACKER_H
#define CRACKER_H

#include <stdint.h>
#include <stdio.h>

#define PASSWD_SIZE 17

#define PSSWD1 0x10BE27ED6F87EC28L
#define PSSWD2 0x4E599B9D5C85489EL
#define PSSWD3 0xEFB8DB41C4D1FD62L

#define ALL_0 0x0000000000000000L
#define ALL_1 0x1111111111111111L
#define ALL_2 0x2222222222222222L
#define ALL_3 0x3333333333333333L
#define ALL_4 0x4444444444444444L
#define ALL_5 0x5555555555555555L
#define ALL_6 0x6666666666666666L
#define ALL_7 0x7777777777777777L
#define ALL_8 0x8888888888888888L
#define ALL_9 0x9999999999999999L
#define ALL_A 0xAAAAAAAAAAAAAAAAL
#define ALL_B 0xBBBBBBBBBBBBBBBBL
#define ALL_C 0xCCCCCCCCCCCCCCCCL
#define ALL_D 0xDDDDDDDDDDDDDDDDL
#define ALL_E 0xEEEEEEEEEEEEEEEEL
#define ALL_F 0xFFFFFFFFFFFFFFFFL

#define START PSSWD3
#define STOP  ALL_F

// no repeated digits past repeats count, 1111DEADBEEF
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

// display percentage of complettion. tick - when to print percentage
void progress(uint64_t number, uint64_t tick);

#endif
