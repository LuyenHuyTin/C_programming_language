/* Given an integer array nums of length n, you want to create an array ans of length 2n where ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).

Specifically, ans is the concatenation of two nums arrays.

Return the array ans. */
#include <stdio.h>
#include <stdlib.h>

int* getConcatenation(int* nums, int numsSize, int* returnSize);

int main() {
    int nums[] = {1, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int* result = getConcatenation(nums, numsSize, &returnSize);

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

int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    int* arr = (int*)malloc(2 * numsSize * sizeof(int));
    *returnSize = 2 * numsSize;

    for (int i = 0; i < numsSize; i++) {
        arr[i] = nums[i];
    }

    int k = 0;
    for (int j = numsSize; j < 2 * numsSize; j++) {
        arr[j] = nums[k];
        k++;
    }

    return arr;
}
