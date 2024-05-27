class Solution {
public:
    void solve(vector<int>& candidates,int idx,vector<int>temp,vector<vector<int>>&ans,int target){
        if(idx==candidates.size()){
            if(target==0){
                ans.push_back(temp); return ;
            }
            return ;
        }

        if(candidates[idx]<=target){ // Picked
            temp.push_back(candidates[idx]);
            solve(candidates,idx,temp,ans,target-candidates[idx]);
            temp.pop_back();
        }
        solve(candidates,idx+1,temp,ans,target); // when not picked
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>ans;

        solve(candidates,0,temp,ans,target);

        return ans;
        
    }
};