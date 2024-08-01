/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
// Helper function for recursive permutation generation
void permuteR(int* nums, int numsSize, int *currIdx, int** retArr, int l, int r)
{
    // Base case: if the current permutation is complete
    if(l == r)
    {
        // Copy the current permutation to the result array
        memcpy(retArr[*currIdx], nums, sizeof(int) * numsSize);
        // Move to the next index in the result array
        *currIdx = *currIdx + 1;
        return;
    }
    // Iterate through possible swaps to generate permutations
    for(int i = l; i <= r; i++)
    {
        // Swap elements at indices l and i
        int temp = nums[l];
        nums[l] = nums[i];
        nums[i] = temp;
        // Recursively generate permutations for the remaining elements
        permuteR(nums, numsSize, currIdx, retArr, l + 1, r);
        // Backtrack: undo the swap to explore other possibilities
        temp = nums[l];
        nums[l] = nums[i];
        nums[i] = temp;
    }
    return;
}
// Main function to generate all permutations
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // Calculate the total number of permutations
    int numPer = 1;
    for(int i = 1; i <= numsSize; i++)
    {
        numPer *= i;
    }
    // Allocate memory for the result array and column sizes array
    int **retArr = malloc(sizeof(int *) * numPer);
    *returnColumnSizes = malloc(sizeof(int) * numPer);
    *returnSize = numPer;
    // Allocate memory for each permutation in the result array
    for(int i = 0; i < numPer; i++)
    {
        retArr[i] = malloc(sizeof(int) * numsSize);
        // Set the column size for each permutation
        (*returnColumnSizes)[i] = numsSize;
    }
    // Initialize index for the current permutation in the result array
    int currIdx = 0;
    // Start the recursive permutation generation
    permuteR(nums, numsSize, &currIdx, retArr, 0, numsSize - 1);
    // Return the result array containing all permutations
    return retArr;
}