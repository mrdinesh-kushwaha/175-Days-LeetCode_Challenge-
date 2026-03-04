class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0;
        int n = nums.size();
        int miniLength = INT_MAX;
        int sum = 0;
    
        for(int right=0;right<n;right++){
            sum+=nums[right];
            
            while(sum>=target){
                miniLength = min(miniLength,right-left+1); 
                sum-=nums[left];
                left++;
            }
            // if(sum==target){
            //     miniLength = min(miniLength,right-left+1); 
            // }
        }
        return miniLength==INT_MAX?0:miniLength;
    }
};