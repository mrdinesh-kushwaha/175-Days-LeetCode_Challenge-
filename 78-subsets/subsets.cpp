// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {

//         vector<vector<int>>ans={{}};

//         for(auto num:nums){

//             int n=ans.size();
//             for(int i=0;i<n;i++){
//                 ans.push_back(ans[i]);
//                 ans.back().push_back(num); //means ans ke last vale element me jao aur usme add kr do
//             }                                // eg: {},{1} ->{1,2} if num=2 
//         }
//         return ans;
//     }
// };

//**USING Recursion//**
class Solution {
public:
    void solve(vector<int>&nums,int idx,vector<int>temp,vector<vector<int>>&ans){
        if(idx==nums.size()){
            ans.push_back(temp);
            return ;
        }
        // pick
        temp.push_back(nums[idx]);
        solve(nums,idx+1,temp,ans);
        // not pick
        temp.pop_back();
        solve(nums,idx+1,temp,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        solve(nums,0,temp,ans);
        return ans;
    }
};