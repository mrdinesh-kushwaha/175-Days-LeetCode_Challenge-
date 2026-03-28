class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int prefix = 0;
        int suffix = 0;
        //Always (prefix of arr[i] + arr[i] + suffix of arr[i] = array of Sum) ke Eqaul HOGA
        int sum=0;
        for(int i:nums) sum+=i;

        // 🔥 check for index 0
        if(sum - nums[0] == 0) return 0;

        for(int i=1;i<nums.size();i++){
            prefix += nums[i-1];
            suffix = sum - nums[i] - prefix;
            if(prefix == suffix) return i;
        }
    return -1;
    }
};