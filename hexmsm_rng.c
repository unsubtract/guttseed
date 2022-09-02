/* hexmsm_rng.c - base-16 Middle-Square Method pseudorandom number generator
 * by unsubtract - MIT license (see LICENSE file) */
#include <stdint.h>
#include "hexmsm_rng.h"

#define NYBBLE 4 /* bits in a hex digit, added for clarity when bitshifting */
static inline uintmax_t hex_digits(uintmax_t n);
static inline uintmax_t hex_pow10(uintmax_t n);

/* printf(3) calls may be uncommented to provide debug information */
uintmax_t hexmsm_next(uintmax_t n)
{
    uintmax_t seedlen, sqrlen;
    seedlen = hex_digits(n);
    n *= n;
 /* printf("sqr: %#x, ", n); */
    sqrlen = hex_digits(n);

    /* digits to remove */
    uintmax_t difference = sqrlen - seedlen;
    uintmax_t left = difference >> 1;
    uintmax_t right = difference - left;
 /* printf("diff: %lu, left: %lu, right: %lu\n", difference, left, right); */

    n %= hex_pow10(sqrlen - left);
    n >>= right * NYBBLE;
    return n;
}


uintmax_t hex_digits(uintmax_t n)
{
    if (n < 0x10) return 1;
    return 1 + hex_digits(n >> NYBBLE);
}

uintmax_t hex_pow10(uintmax_t n)
{
    /* left-shifting by n digits is equal to repeated multiplication by 0x10
     * this is much, much faster than what the compiler otherwise produces */
    return 0x1 << (n * NYBBLE);
}
