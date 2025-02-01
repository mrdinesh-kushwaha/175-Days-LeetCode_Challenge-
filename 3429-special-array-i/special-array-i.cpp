class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]%2==nums[i+1]%2) // means same parity then return false:
                return false;
        }
        return true;  
    }
};