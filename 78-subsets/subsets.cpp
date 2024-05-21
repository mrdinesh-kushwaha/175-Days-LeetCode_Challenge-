class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>>ans={{}};

        for(auto num:nums){

            int n=ans.size();
            for(int i=0;i<n;i++){
                ans.push_back(ans[i]);
                ans.back().push_back(num); //means ans ke last vale element me jao aur usme add kr do
            }                                // eg: {},{1} ->{1,2} if num=2 
        }
        return ans;
    }
};