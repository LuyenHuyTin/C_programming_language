/* Write a function that takes the binary representation of an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

Note:

Note that in some languages, such as Java, there is no unsigned integer type. In this case, the input will be given as a signed integer type. It should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 3, the input represents the signed integer. -3. */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

int hammingWeight(uint32_t n) {
    uint32_t *ptr = (uint32_t*)malloc(32*sizeof(uint32_t));
    for(int i=0;i<32;i++){
        *(ptr+i) = n%2;
        n=n/2;
    }
    int k=0;
    for(int i=0;i<32;i++){
        if(*(ptr+i)==1){
            k++;
        }
    }
    free(ptr);
    return k;
}

int main() {
    uint32_t n = 0b00000010100101000001111010011100; // binary representation of 43261596
    int k = hammingWeight(n);
    printf("Number of 1 bits in %u: %d\n", n, k);
    return 0;
}
