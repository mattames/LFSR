#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    uint64_t lfsr = 0x1234567890ABCDEFLL; //start value  
    uint8_t cnt = 0;
    printf("Initial Value:- %016llx\n", lfsr);
    
    for(cnt=0;cnt<64;cnt++)
    {
	// Polynomial is C(x) = 1 + x^15 + x^27 + x^38 + x^46 + x^62 + x^64
        uint64_t bit  = ((lfsr >> 63) ^ (lfsr >> 61) ^ (lfsr >> 45) ^ (lfsr >> 37) ^ (lfsr >> 26) ^ (lfsr >> 14)) & 0x1;
        lfsr =  (lfsr << 1) | (bit);
        printf("shift #%i, %016llx\n", (cnt+1), lfsr);
    }
    printf("Next MI:- %016llx\n", lfsr);
    return 0;
}
