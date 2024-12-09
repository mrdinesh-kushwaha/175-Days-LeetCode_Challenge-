class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> cum(n, 0);
        vector<bool> ans;

        for (int i = 1; i < n; i++) {
            cum[i] = cum[i - 1];
            if (nums[i] % 2 == nums[i - 1] % 2) {
                cum[i]++;
            }
        }

        for (auto& q : queries) {
            int x = q[0], y = q[1];
            int falseCount = cum[y] - (x > 0 ? cum[x] : 0);
            if (falseCount && x != y)
                ans.push_back(false);
            else
                ans.push_back(true);
        }

        return ans;
    }
};