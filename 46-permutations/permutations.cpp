class Solution {
public:
void solve(vector<int>&nums,vector<int>temp,vector<vector<int>>&ans,int freq[]){
    if(temp.size()==nums.size()){
        ans.push_back(temp);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(!freq[i]){ // means mark nhi hai in freq, freq[i]!=1
        freq[i]=1;
        temp.push_back(nums[i]);
        solve(nums,temp,ans,freq);
        freq[i]=0;
        temp.pop_back();
        }
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        int freq[nums.size()];
        for(int i=0;i<nums.size();i++) freq[i]=0;
        vector<int>temp;
        vector<vector<int>>ans;
        solve(nums,temp,ans,freq);
        return ans;
        
    }
};