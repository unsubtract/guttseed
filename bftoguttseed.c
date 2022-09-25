/* bftoguttseed.c - guttseed program brute-forcer (see README file)
 * by unsubtract - MIT license (see LICENSE file) */
#include <inttypes.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "guttseed.h"
#include "hexmsm_rng.h"

#define BUF_SIZE 2048

int main(void)
{
    uintmax_t i;

    char *input = malloc(BUF_SIZE);
    fgets(input, BUF_SIZE, stdin);
    input[strcspn(input, "\r\n")] = 0; /* strip newline */

    size_t outsize = strlen(input) + 1;
    char *output = malloc(outsize);
    
    for (i = 0; i < 0x9999; ++i) {
        guttseed(outsize, i, output);
        if (strcmp(input, output) == 0) break;
    }

    printf("%"PRIuMAX" %"PRIxMAX"\n", strlen(output), i);
    return EXIT_SUCCESS;
}
