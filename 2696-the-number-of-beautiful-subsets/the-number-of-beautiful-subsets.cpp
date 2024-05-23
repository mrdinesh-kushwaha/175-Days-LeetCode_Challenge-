class Solution {
public:
void solve(int idx,vector<int>&nums,unordered_map<int,int>& mp,int& ans,int &k){

    if(idx==nums.size()){
        ans++;
        return;
    }
    // not take
    solve(idx+1,nums,mp,ans,k);

    //take
    if(!mp[nums[idx]-k] && !mp[nums[idx]+k]){
        mp[nums[idx]]++; // do
        solve(idx+1,nums,mp,ans,k); // explore
        mp[nums[idx]]--; // backtrack
    }
}
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int ans=0;

        solve(0,nums,mp,ans,k);
        return ans-1; // bcz add null subset(-1)
    }
};