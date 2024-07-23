class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int >mp;
        for(auto i:nums){
            mp[i]++;
        }
        sort(nums.begin(),nums.end(),[&](int a,int b){ // this is lambda funtion 
            return mp[a]!=mp[b] ? mp[b]>mp[a]:a > b;  //compare
        });
        return nums;
    }
};