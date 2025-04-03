class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    // Brute Force Approach
    // for(int i=0;i<nums.size()-1;i++){
    //     for(int j=i+1;j<nums.size();j++){

    //         if((nums[i]+nums[j])==target) return{i,j};
    //     }
    // }
    // return {-1,-1};

    // Approach-2 Hash Map
    unordered_map<int,int>mp;
    for(int i=0;i<nums.size();i++){
        mp[nums[i]]=i;
    }
    for(int i=0;i<nums.size();i++){
        int ele=target-nums[i];

        if(mp.find(ele)!=mp.end() && mp[ele]!=i) return {i,mp[ele]};
    }
    return {-1,-1};
    }
};