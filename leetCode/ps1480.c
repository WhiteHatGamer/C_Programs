#include <stdio.h>
//1480. Running Sum of 1d Array

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
}

void main()
{
    //code here
}