/* Write a program to swap the endianness of a 32-bit unsigned integer. That is, swap the byte order such that the first byte becomes the fourth byte, the second byte becomes the third byte, and so on.*/
#include <stdio.h>

int swapendian(int a){
    int byte1 = (a & 0xFF000000) >> 24;
    int byte2 = (a & 0x00FF0000) >> 8;
    int byte3 = (a & 0x0000FF00) << 8;
    int byte4 = (a & 0x000000FF) << 24;
    return byte1 | byte2 | byte3 | byte4;
}

int main() {
    unsigned int value = 0x12345678;
    unsigned int swappedValue = swapendian(value);
    printf("Original value: 0x%08X\n", value);
    printf("Swapped value:  0x%08X\n", swappedValue);
    return 0;
}
