/* Given two binary strings a and b, return their sum as a binary string.
Example 1:
Input: a = "11", b = "1"
Output: "100"
Example 2:
Input: a = "1010", b = "1011"
Output: "10101" */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char *addBinary(char *a, char *b);

int main() {
    char *a = "01";
    char *b = "101";
    char *result = addBinary(a, b);
    if (result != NULL) {
        //printf("%s\n", result);
        free(result);
    }
    return 0;
}

char *addBinary(char *a, char *b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int len = len_a > len_b ? len_a : len_b;
    char *res = (char *) malloc((len + 2) * sizeof(char)); // allocate memory for result string
    if (res == NULL) {
        printf("Error: memory allocation failed.\n");
        exit(1);
    }
    int carry = 0;
    int i = len_a - 1;
    int j = len_b - 1;
    int k = len;
    res[k + 1] = '\0';
    while (i >= 0 || j >= 0) {
        int sum = carry;
        printf("sum first: %d\n", sum);
        if (i >= 0) {
            sum += a[i] - '0';
            printf("i sum:%d and a[i]:%d\n", sum, a[i]);
            i--;
        }
        if (j >= 0) {
            printf("sum:%d\n", sum);
            sum += b[j] - '0';
            printf("j sum:%d and b[i]:%d\n", sum, b[j]);
            j--;
        }
        printf("sum:%d\n",sum);
        carry = sum / 2;
        res[k] = sum % 2 + '0';
        printf("res[k]: %c\n", res[k]); 
        printf("k trong while: %d\n", k);
        k--;
        //printf("k trong while: %d\n", k);
    }
    if (carry == 1) {
        printf("k: %d\n", k);
        res[k] = '1';
        return res;
    } else {
        return res + 1;
    }
}

