class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // int n = nums.size();
        // sort(nums.begin(),nums.end());
        // vector<int> ans;

        // if (nums[0] != nums[1]) ans.push_back(nums[0]);
        // if (nums[n-1] != nums[n-2]) ans.push_back(nums[n-1]);

        // for (int i = 1; i < n-1; i++){
        //     if (nums[i-1] != nums[i] && nums[i+1] != nums[i]) ans.push_back(nums[i]);
        // }
        // return ans;

        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<int>ans;
        for(auto &i:mp){
            if(i.second==1)
            ans.push_back(i.first);
        }
        return ans;
    }
};