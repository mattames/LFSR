#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    uint32_t lfsr = 0x12345678;
    uint8_t cnt = 0;
    printf("Initial Value:- 0x%08x\n", lfsr);
 
    for(cnt=0;cnt<32;cnt++)
    {
	// Polynomial is C(x) = x^32 + x^4 + x^2 + 1
        uint32_t bit  = ((lfsr >> 31) ^ (lfsr >> 3) ^ (lfsr >> 1)) & 0x1;
        lfsr =  (lfsr << 1) | (bit);
        printf("shift #%i, 0x%08x\n", (cnt+1), lfsr);
    }
    printf("Next MI:- 0x%08x\n", lfsr);
    return 0;
}

