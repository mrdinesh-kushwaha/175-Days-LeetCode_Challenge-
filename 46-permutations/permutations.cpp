// class Solution {
// public:
// void solve(vector<int>&nums,vector<int>temp,vector<vector<int>>&ans,int freq[]){
//     if(temp.size()==nums.size()){
//         ans.push_back(temp);
//         return;
//     }
//     for(int i=0;i<nums.size();i++){
//         if(!freq[i]){ // means mark nhi hai in freq, freq[i]!=1
//         freq[i]=1;
//         temp.push_back(nums[i]);
//         solve(nums,temp,ans,freq);
//         freq[i]=0;
//         temp.pop_back();
//         }
//     }
// }
//     vector<vector<int>> permute(vector<int>& nums) {
//         int freq[nums.size()];
//         for(int i=0;i<nums.size();i++) freq[i]=0;
//         vector<int>temp;
//         vector<vector<int>>ans;
//         solve(nums,temp,ans,freq);
//         return ans;

//         // T.C= O(!n*n) S.C=O(N)+O(N)
//     }
// };

class Solution { // OPTIMISE SPACE COMPLEXITY::
public:
void solve(vector<int>&nums,int idx,vector<vector<int>>&ans){

    if(idx==nums.size()){
        ans.push_back(nums); return;
    }
    for(int i=idx;i<nums.size();i++){
        swap(nums[idx],nums[i]);
        solve(nums,idx+1,ans);
        swap(nums[idx],nums[i]); // means reForm original position:::
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>>ans;
    solve(nums,0,ans);
    return ans;
   }
};