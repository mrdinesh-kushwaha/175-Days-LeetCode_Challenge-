class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
        int inc=1,d=1;
        int maxi=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]>nums[i]){
                inc++;
                d=1;
            }
            else if(nums[i+1]<nums[i]){
                d++;
                inc=1;
            }
            else{
                inc=1;
                d=1;
            }
            maxi=max(maxi,max(inc,d));
        }
        return maxi;
    }
};