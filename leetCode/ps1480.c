//1480. Running Sum of 1d Array

#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize){
    int* toReturn = (int*) malloc (numsSize * sizeof(int));
    toReturn[0] = nums[0];
    for (int i=1;i<numsSize;i++)
    {
        toReturn[i] = toReturn[i-1] + nums[i];
    }
    *returnSize = numsSize;
    return (toReturn);
    // time complexity = O(n)
    // space complexity = O(1) Since we are not creating any extra variables other than input and output
    // we can also solve this by updating the input array but not a good standard   
}


void main()
{
    //code here
}