class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        
        long long total_sum = 0;
        int n = nums.size();
        for(auto& num : nums){
            total_sum += num;
        }
        int count=0;
        long long currSum=0;
        for(int i=0;i<n-1;i++){
            currSum+=nums[i];

            if(currSum >= total_sum - currSum){ 
                count++;
            }
        }
        return count;
    }
};