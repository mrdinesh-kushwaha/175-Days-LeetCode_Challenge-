class Solution {
public:
    void solve(vector<int>& arr, int target,int idx,vector<int>temp,vector<vector<int>>&ans){
        //base case:
        if(target==0){
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<arr.size();i++){
            if(i>idx && arr[i]==arr[i-1]) continue;
            if(arr[i] > target) break;

            temp.push_back(arr[i]); // store solution 
            solve(arr,target-arr[i],i+1,temp,ans); //call recursion for next cobination

            temp.pop_back(); // pop the element for remain same 
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>ans; // for store all the combination
        sort(begin(candidates),end(candidates));
        solve(candidates,target,0,temp,ans);

        return ans;
    }
};