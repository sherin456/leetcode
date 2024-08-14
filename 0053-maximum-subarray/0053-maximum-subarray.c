int maxSubArray(int* nums, int numsSize) {
    int mx=INT_MIN;
    int t=0;
    for(int i=0;i<numsSize;i++)
    {
        t+=nums[i];
        t=t>nums[i]?t:nums[i];
        mx=t>mx?t:mx;
    }
    return mx;
}