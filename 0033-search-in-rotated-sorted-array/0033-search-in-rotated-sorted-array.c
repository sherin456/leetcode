int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    while(left <= right){
        if(nums[left] == target){
            return left;
        }
        else if(nums[right] == target){
            return right;
        }else{
            left ++;
            right --;
        }
    }
    return -1;
}