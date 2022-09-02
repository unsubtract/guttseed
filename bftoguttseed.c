/* bftoguttseed.c - guttseed program brute-forcer (see README file)
 * by unsubtract - MIT license (see LICENSE file) */
#include <inttypes.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "guttseed.h"
#include "hexmsm_rng.h"

int main(void)
{
    /* actually reading user input is coming soon (maybe) */
    const char* const desired_output = "-[------->+<]>-.";
    
    const size_t bufsize = strlen(desired_output) + 1;
    char *outstr = malloc(bufsize);
    uintmax_t i;

    for (i = 0; i < 0x9999; ++i) {
        guttseed(bufsize, i, outstr);
        if (strcmp(desired_output, outstr) == 0) break;
    }
    printf("%s %lu %#lx\n", outstr, strlen(outstr), i);
    return 0;
}
