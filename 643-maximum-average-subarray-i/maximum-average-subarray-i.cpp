class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if(nums.size()<k) return 0;
        double sum=0;
        int size = nums.size();

        for(int i=0;i<k;i++){
            sum+=nums[i];
        }

        // now increase and decrease windows
        double ans = sum;
        for(int i=k;i<size;i++){
            sum += nums[i]-nums[i-k];
            ans = max(ans,sum);
        }

        return ans/k;
    }
};