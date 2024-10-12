class Solution {
public:
    int findOR(int n) {
        for (int i = 0; i <= n; i++) {
            if ((i | (i + 1)) == n) return i;
        }
        return -1;
    }

    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            ans[i] = findOR(nums[i]);
        }
        return ans;
    }
};