/* Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

Return the array in the form [x1,y1,x2,y2,...,xn,yn].*/
#include <stdio.h>
#include <stdlib.h>

int* shuffle(int* nums, int numsSize, int n, int* returnSize);

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int n = numsSize / 2;
    int returnSize;
    
    int* result = shuffle(nums, numsSize, n, &returnSize);
    
    printf("Input array:\n");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    
    printf("Output array:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    
    free(result);
    return 0;
}

int* shuffle(int* nums, int numsSize, int n, int* returnSize) {
    int* arr = (int*)malloc(2 * n * sizeof(int));
    *returnSize = 2 * n;
    
    int k = 0;
    int j = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (i % 2) {
            arr[i] = nums[j + n];
            j++;
        }
        else {
            arr[i] = nums[k];
            k++;
        }
    }
    
    return arr;
}
