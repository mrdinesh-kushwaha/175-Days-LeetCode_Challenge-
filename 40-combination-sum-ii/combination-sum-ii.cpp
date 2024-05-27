class Solution {
public:
    void solve(vector<int>& candidates, int idx, vector<int> temp, vector<vector<int>>& ans, int target) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }
        
        for(int i = idx; i < candidates.size(); i++) {
            if(i > idx && candidates[i] == candidates[i-1]) continue; // Skip duplicates
            if(candidates[i] > target) break; // No need to proceed further if the current number exceeds the target
            
            temp.push_back(candidates[i]);
            solve(candidates, i+1, temp, ans, target - candidates[i]);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // Sort the candidates to handle duplicates
        vector<int> temp;
        vector<vector<int>> ans;
        solve(candidates, 0, temp, ans, target);
        return ans;
    }
};
