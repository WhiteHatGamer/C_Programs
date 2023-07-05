//1. Two Sum
#include <stdio.h>
#include <stdlib.h>

// Time Complexity O(n^2)
int* twoSumn2(int* nums, int numsSize, int target, int* returnSize){
    int* ar = (int*)malloc(2*sizeof(int));
    if(!ar){
      return 0;
    }
    for (int i=0;i<numsSize - 1;i++){
        for(int j=i+1;j<numsSize;j++){
            if ((nums[i]+nums[j]) == target){
                ar[0]=i;
                ar[1]=j;
                *returnSize = 2;
                return ar;
            }
        }
    }
    free(ar);
    *returnSize = 0;
    return 0;
}

// Better Solution

// Time Complexity O(n) PS: Only sorted array
int* twoSumnlogn(int* nums, int numsSize, int target, int* returnSize){
    int* ar = (int*)malloc(2*sizeof(int));
    if(!ar){
        return 0;
    }
    int indxA = 0, indxB = numsSize-1;
    int sum = 15;
    while(indxA<indxB){
        sum = nums[indxA] + nums[indxB];
        if (sum == target){
            ar[0]=indxA;
            ar[1]=indxB;
            *returnSize = 2;
            // printf("A=%i, B= %i\n",ar[0],ar[1]);
            return ar;
        }
        if(sum<target){
            indxA++;
        }
        else if(sum>target){
            indxB--;
        }
    }
    free(ar);
    *returnSize = 0;
    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* ar = (int*)malloc(2*sizeof(int));
    if(!ar){
        return NULL;
    }

    int capacity = numsSize*2;
    int* hashTable;
    if(target==0){
        hashTable = (int*)malloc(capacity * sizeof(int));
    }
    else{
        hashTable = (int*)calloc(capacity, sizeof(int));
    }   
    if(!hashTable){
        free(ar);
        return NULL;
    }

    for (int i = 0; i < numsSize; i++) {
        int key = i;
        int complement = target - nums[i];
        int indx = 0;
        do
        {
            if (indx == i){
                break;
            }
            if (hashTable[indx] == nums[i]) {
                ar[0] = indx;
                ar[1] = i;
                free(hashTable);
                *returnSize = 2;
                return ar;
            }
            indx++;
        } while (indx<capacity);

        hashTable[key] = complement;

    }

    free(hashTable);
    free(ar);
    *returnSize = 0;
    return NULL;
}

int main() {
    int nums[] = {2,5,5,11};
    int target = 10;
    int returnSize;
    int* result = twoSum(nums, sizeof(nums) / sizeof(nums[0]), target, &returnSize);
    if (result) {
        printf("Indices: %d, %d\n", result[0], result[1]);
        free(result);
    } else {
        printf("No two elements sum up to the target.\n");
    }
    return 0;
}