class Solution {
public:
    vector<vector<int>>result;
    void twoSum(vector<int>&nums,int target,int i,int j){
        while(i<j){
            if(nums[i]+nums[j] < target) i++;
            else if(nums[i]+nums[j]>target) j--;
            else{
                //remove deplicate first
                while(i<j && nums[i]==nums[i+1]) i++;
                while(i<j && nums[j]==nums[j-1]) j--;

                result.push_back({-target,nums[i],nums[j]});
                i++,j--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {

        // int target = 0;
        // sort(nums.begin(), nums.end());
        // set<vector<int>> s;
        // vector<vector<int>> output;
        // for (int i = 0; i < nums.size(); i++){
        //     int j = i + 1;
        //     int k = nums.size() - 1;
        //     while (j < k) {
        //         int sum = nums[i] + nums[j] + nums[k];
        //         if (sum == target) {
        //             s.insert({nums[i], nums[j], nums[k]});
        //             j++;
        //             k--;
        //         } else if (sum < target) {
        //             j++;
        //         } else {
        //             k--;
        //         }
        //     }
        // }
        // for(auto triplets : s)
        //     output.push_back(triplets);
        // return output;

        //***Solve this problem convert into TwoSum Problem
        // n1+n2+n3=0 -> n2+n3 = -n1(target)
        result.clear();
        int n=nums.size();
        if(n < 3) return {};
        sort(begin(nums),end(nums));

        for(int i=0;i<n-2;i++){
            if(i > 0 && nums[i]==nums[i-1]) continue;

            int n1 = nums[i];
            int target = -n1;

            twoSum(nums,target,i+1,n-1);
        }
        return result;
    
    }
};