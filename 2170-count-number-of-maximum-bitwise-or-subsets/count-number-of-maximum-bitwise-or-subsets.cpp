class Solution {
public:
    int max_or, count;
    
    void dfs(vector<int>& nums, int idx, int curr_or) {
        // If we've OR'ed enough to reach the end of the array
        if (idx == nums.size()) {
            // If this subset has the maximum OR, increase the count
            if (curr_or == max_or) count++;
            return;
        }
        
        // Option 1: Include nums[idx] in the subset
        dfs(nums, idx + 1, curr_or | nums[idx]);
        
        // Option 2: Exclude nums[idx] from the subset
        dfs(nums, idx + 1, curr_or);
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        max_or = 0;
        count = 0;
        
        // Compute the maximum bitwise OR of the entire array
        for (int num : nums) {
            max_or |= num;
        }
        
        // Start the DFS/backtracking to count subsets with maximum OR
        dfs(nums, 0, 0);
        
        return count;
    }
};