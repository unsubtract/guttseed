/* guttseedtobf.c - guttseed compiler (see README file)
 * by unsubtract - MIT license (see LICENSE file) */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "guttseed.h"
#include "hexmsm_rng.h"

int main(void)
{
    /* actually reading user input is coming soon (maybe) */
    const size_t prg_bufsize = 6;
    const uintmax_t seed = 0x3e5;
    
    char* prg = malloc(prg_bufsize);
    guttseed(prg_bufsize, seed, prg);
    puts(prg);
    return 0;
}
