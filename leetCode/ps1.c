//1. Two Sum

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
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