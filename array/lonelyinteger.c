/*Given an array of integers, where all elements but one occur twice, find the unique element.

Example
a = [1,2,3,4,3,2,1]

The unique element is 4.

Function Description

Complete the lonelyinteger function in the editor below.

lonelyinteger has the following parameter(s):

int a[n]: an array of integers
Returns

int: the element that occurs only once */
#include <stdio.h>

int lonelyinteger(int a_count, int* a);

int main() {
    int a[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    int a_count = sizeof(a) / sizeof(a[0]);
    
    int result = lonelyinteger(a_count, a);
    
    printf("Input array:\n");
    for (int i = 0; i < a_count; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    printf("Lonely integer: %d\n", result);
    
    return 0;
}

int lonelyinteger(int a_count, int* a) {
    int count = 0;
    int tmp;
    
    for (int i = 0; i < a_count; i++) {
        count = 0;
        for (int j = 0; j < a_count; j++) {
            if (a[i] == a[j]) {
                count++;
            }
        }
        if (count == 1) {
            tmp = a[i];
            break;
        }
    }
    
    return tmp;
}
