/* Complete the maximizingXor function in the editor below. It must return an integer representing the maximum value calculated.

maximizingXor has the following parameter(s):

l: an integer, the lower bound, inclusive
r: an integer, the upper bound, inclusive */
#include <stdio.h>

int maximizingXor(int l, int r);

int main() {
    int l = 10;
    int r = 15;
    
    int result = maximizingXor(l, r);
    
    printf("l: %d\n", l);
    printf("r: %d\n", r);
    printf("Maximizing XOR value: %d\n", result);
    
    return 0;
}

int maximizingXor(int l, int r) {
    int i = 0;
    int j = 0;
    int max = 0;
    
    if (l > r) {
        i = r;
        j = l;
    }
    else {
        i = l;
        j = r;
    }
    
    for (int k = i; k < j; k++) {
        for (int h = k; h < j; h++) {
            if (max < (k ^ h)) {
                max = k ^ h;
            }
        }
    }
    
    return max;
}
