class Solution {
public:
    int minDifference(vector<int>& nums) {
        int ans=INT_MAX;
        int n=nums.size();
        sort(begin(nums),end(nums));    
        if(n>=4){
        ans=min(ans,nums[n-4]-nums[0]); //last ke tin
        ans=min(ans,nums[n-1]-nums[3]); // first ke tin
        ans=min(ans,nums[n-3]-nums[1]); // last ke do, first ke ek
        ans=min(ans,nums[n-2]-nums[2]); // last ke ek , first ke do
        }
        else return 0;
        
        return ans;
    }
};