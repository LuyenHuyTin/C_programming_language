/* Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space. */
#include <stdio.h>

int singleNumber(int* nums, int numsSize) {
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        result ^= nums[i];
    }
    return result;
}

int main() {
    int nums[] = {2, 3, 4, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = singleNumber(nums, numsSize);
    printf("The single number is %d\n", result);
    return 0;
}
