class Solution {
public:
void solve(vector<int>&nums,int& target,int idx,int currSum,int& count){
    if(idx==nums.size()){
        if(currSum==target) count++;
    }
    else{
        solve(nums,target,idx+1,currSum+nums[idx],count); // Take '+'
        solve(nums,target,idx+1,currSum-nums[idx],count); // Take '-'
    }
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int count=0;
        solve(nums,target,0,0,count);
        return count;
    }
};