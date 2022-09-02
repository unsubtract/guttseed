/* guttseed.c - guttseed main file (see README file)
 * by unsubtract - MIT license (see LICENSE file) */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "guttseed.h"
#include "hexmsm_rng.h"

static const char* const instr = "+-><.,[]";

void guttseed(size_t size, uintmax_t seed, char *outstr)
{
    for (size_t i = 0; i < size - 1; ++i) {
        seed = hexmsm_next(seed);
        outstr[i] = instr[seed % 8];
    }
    outstr[size] = '\0';
    return;
}
