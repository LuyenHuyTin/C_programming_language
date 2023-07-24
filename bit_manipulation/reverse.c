/* Reverse bits of a given 32 bits unsigned integer.

Note:

Note that in some languages, such as Java, there is no unsigned integer type. In this case, both input and output will be given as a signed integer type. They should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 2 above, the input represents the signed integer -3 and the output represents the signed integer -1073741825. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t m = n;
    printf("n: %u\n", n);
    uint32_t *ptr = (uint32_t*)malloc(32*sizeof(uint32_t));
    for(int i=0;i<32;i++){
        *(ptr+i) = m%2;
        m=m/2;
    }
    m = 0;
    for(int i=0;i<32;i++){
        if(*(ptr+i)==1){
            m = m + pow(2,32-1-i);
        }
    }
    free(ptr);
    printf("m: %u\n", m);
    return m;
}

int main() {
    uint32_t n = 0b00000010100101000001111010011100; // binary representation of 43261596
    uint32_t m = reverseBits(n);
    printf("Original: %u\nReversed: %u\n", n, m);
    return 0;
}
