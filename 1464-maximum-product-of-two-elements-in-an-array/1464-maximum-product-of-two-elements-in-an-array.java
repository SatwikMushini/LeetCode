class Solution {
    public int maxProduct(int[] nums) {
        int largest = nums[0];
        int secondLargest = 0;
        for(int i = 1; i < nums.length; i++){
            if(nums[i] > largest){
                secondLargest = largest;
                largest = nums[i];
            }
            else if(nums[i] > secondLargest)secondLargest = nums[i];
        }
        return (largest-1)*(secondLargest-1);
    }
}