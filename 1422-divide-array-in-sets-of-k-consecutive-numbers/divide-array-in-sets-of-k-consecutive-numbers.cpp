class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        // base case:
        if(nums.size() % k !=0) return false; // divisible not possible in k group

        map<int,int>mp;
        for(auto i: nums) mp[i]++;

        while(!mp.empty()){
            int curr= mp.begin()->first;

            for(int i=0;i<k;i++){
                if(mp[curr+i]==0) return false; // means freq Zero ho , then can't create group

                mp[curr+i]--; // freq reduce kr do
                if(mp[curr+i]<1) mp.erase(curr+i); // remove kr do map se whem freq has zero
            }
        }
    return true;
        
    }
};