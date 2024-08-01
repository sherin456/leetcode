void get(int *q, int *size, int *item) {
    int i = 0;
    *item = q[i];
    q[i] = q[(*size)-1];
    down(q, i, (*size)--);
}
void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}
void down(int *q, int p, int size) {
    while (p < size) {
        if (p*2+2 < size && q[p*2+2] <= q[p*2+1]) {
            if (q[p*2+2] < q[p])
                swap(&q[p*2+2], &q[p]);
            p = p*2+2;
        } else if (p*2+1 < size && q[p*2+1] < q[p]) {
            swap(&q[p*2+1], &q[p]);
            p = p*2+1;
        }
        else {
            p = p*2+1;
        }
    }
}
int* make(int *nums, int size) {
    int *q = (int*)malloc(size * sizeof(int));
    for(int i = 0; i < size; i++)
        q[i] = nums[i];

    for (int x = (size-1) / 2; x >= 0; x--)
        down(q, x, size);
    return q;
}
int* sortArray(int* nums, int numsSize, int* returnSize) {
    int size = numsSize;
    int *q = make(nums, numsSize);
    int item;
    for(int i = 0; i < numsSize; i++) {
        get(q, &size, &item);
        nums[i] = item;
    }
    *returnSize = numsSize;
    return nums;
}