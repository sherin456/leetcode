int removeDuplicates(int* nums, int numsSize) {
     if (numsSize == 0) return 0;
    int i=0,j=0,x,b=0,t=0,m,k=0;
    int temp[10000];
    while(j<numsSize)
    {  
        b=0;
    x = nums[j];
    while(i<numsSize && nums[i] == x)
    {
        b++;
        m = i;
        i++;
    }
    if (b >= 2)
    {
        temp[t] = x ;
        t++;
        temp[t] = x;
        t++;
    }
    else
    {
        temp[t] = x;
        t++;
    }
    j = m+1;
    }
    while(k<t)
    {
        nums[k] = temp[k];
        k++;
    }
    return t;
}