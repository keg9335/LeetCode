int singleNumber(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        int flag = 0;
        for (int j = 0; j < numsSize; j++) {
            if (i != j && nums[i] == nums[j]){
                flag = 1;
                break;
            }
        }
        if (!flag) return nums[i];
    }
    return NULL;
}