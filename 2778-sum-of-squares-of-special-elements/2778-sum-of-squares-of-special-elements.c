int sumOfSquares(int* nums, int size) {
    int res = 0;
    for(int i = 1; i <= size; i++){
        if(size % i == 0)res += pow(nums[i - 1], 2);
    }
    return res;
}