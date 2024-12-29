class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int>mp;
    for(int i=0;i<nums.size();i++){
        int num = target-nums[i];
        if(mp.find(num)!=mp.end()){
            return {i,mp[num]};
        }
        mp[nums[i]]=i;
    }
    return {};
    }
};