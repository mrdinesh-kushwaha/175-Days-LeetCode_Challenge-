class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        sort(begin(nums),end(nums));
        int cnt=1;
        int result = INT_MIN;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1]) continue;
            if((nums[i]+1) == nums[i+1]) cnt++; 
            if((nums[i]+1) != nums[i+1]){
                result=max(result,cnt);
                cnt=1;
            }
        }
        result=max(cnt,result);  
        return result;
    }
};