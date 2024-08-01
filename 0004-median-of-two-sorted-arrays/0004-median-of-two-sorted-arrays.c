double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // track 2 indexes to iterate through the arrays + a view index to track total items viewed
    // advance an index only when we record the smaller of the 2 values
    // we can compute the position in the median in advance
    // for even lengths we need to average both medians 
    const int comboSize = nums1Size + nums2Size;
    int prev = 0;
    int curr = 0;

    int i = 0;
    int j = 0;
    int v = 0;

    while (v <= comboSize / 2){
        prev = curr;
        if (i < nums1Size && (j >= nums2Size || nums1[i] <= nums2[j])) {
            curr = nums1[i];
            i++;
        } else if (j < nums2Size) {
            curr = nums2[j];
            j++;
        }
        // printf("%i\n", curr);
        v++;
    }
    if (comboSize % 2 != 0) {
        return curr;
    }
    return (prev + curr) / 2.0;
}