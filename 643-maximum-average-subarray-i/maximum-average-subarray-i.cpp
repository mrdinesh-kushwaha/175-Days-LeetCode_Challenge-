class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if(nums.size()<k) return 0;
        double maxiAns = INT_MIN;
        double sum=0;
        int left=0;
        for(int right=0;right<nums.size();right++){
            sum+=nums[right];

            if(right-left+1 == k){
                double temp = sum / k;
                maxiAns = max(maxiAns,temp);
                sum-=nums[left];
                left++;
            }
        }
        return maxiAns;
    }
};