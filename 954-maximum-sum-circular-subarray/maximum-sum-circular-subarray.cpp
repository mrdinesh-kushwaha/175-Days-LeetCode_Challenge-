class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        //total 3 cases
        // case-1 Normal kadane(find masxSum)
        // case-2 Circular array then (totalSum - minSum(remove worst part of subarray))
        // case-3 Given all element neg(-ve) then return (maxSum) Normal kadane 

        int maxSum = nums[0];
        int minSum = nums[0];
        int currMax = nums[0];
        int currMin = nums[0];
        int totalSum = nums[0];

        for(int i=1;i<nums.size();i++){
            //Case-1 Normal kadane (maximum Subarray)
            currMax = max(nums[i], currMax+nums[i]);
            maxSum = max(maxSum, currMax);

            //Case-2 Circular kadane
            currMin = min(nums[i], currMin+nums[i]);
            minSum = min(minSum, currMin);

            //Case-3 total Sum for checking all ele (-ve) or Not
            totalSum += nums[i]; 
        }
        // if all ele negative(-ve)
        if(totalSum == minSum) return maxSum;

        return max(maxSum, totalSum-minSum);
    }
};