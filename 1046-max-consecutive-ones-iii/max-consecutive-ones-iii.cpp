class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int f1 = 0, ws = 0;
        int ans = INT_MIN;
        int left=0;

        for(int right=0;right<n;right++){
            if(nums[right]==1) f1++;
            ws = right -left+1;
            while(ws-f1 > k){
                if(nums[left]==1) f1--;
                left++;
                ws = right-left+1;
            }
            if(ws-f1<=k)
            ans = max(ans,right-left+1);
        }
        return ans;
    }
};