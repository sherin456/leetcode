int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int ll=0,hl=numsSize-1,mid,i=0,j=0,k=0;
    int *res=malloc(2*(sizeof(int)));
    while((ll<=hl)&&k==0)
    {
        mid=(ll+hl)/2;
        if(nums[mid]==target)
        {
            k=1;
            i=j=mid;
        }
        else if(nums[mid]>target)
            hl=mid-1;
        else
            ll=mid+1;
    }
    if(k==1)
    {
        while((0<=i)&&(nums[i]==target))
            i--;
        i++;
        while(j<numsSize&&nums[j]==target)
            j++;
        j--;
    }
    else
    i=j=-1;
    res[0]=i;
    res[1]=j;
    *returnSize=2;
    return res;
}