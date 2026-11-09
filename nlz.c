/*
* nlz.c - Project 1 starting program
*
* Adds up the number of leading zeros (NLZ) of every 64-bit integer
* from 0 to 1,000,000,000 and reports how long that took.
* (c) Dr. Sari Sultan
*/
#include <stdio.h>
#include <stdint.h>
#include <time.h>
static inline int nlz(uint64_t x)
{
    int n = 0;
    for (uint64_t mask = 1ULL << 63; mask != 0 && (x & mask) == 0; mask >>= 1)
        n++;
    return n;
}
/*
* Do not change this function
*/
int main(void)
{
    struct timespec start, end;
    uint64_t sum = 0;
    
    timespec_get(&start, TIME_UTC);
    for (uint64_t i = 0; i <= 1000000000; i++)
        sum += nlz(i);
    timespec_get(&end, TIME_UTC);

    double seconds = (end.tv_sec - start.tv_sec)
                   + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Sum of leading zeros: %llu\n", (unsigned long long)sum);
    printf("Time: %.4f s\n", seconds);
    return 0;
}