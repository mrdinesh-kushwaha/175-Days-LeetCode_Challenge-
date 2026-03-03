class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            
            for(int j=i+1;j<n-2;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;

                int left = j+1;
                int right = n-1;

                //Now 2-pointer Approach
                while(left<right){
                    long long sum = nums[i] + nums[j];
                    sum += nums[left] + nums[right];
                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                        left++;
                        right--;

                        //for deplicate
                        while(left<n && nums[left]==nums[left-1]) left++;
                        while(right>=0 && nums[right]==nums[right+1]) right--;
                    }
                    else if(sum < target) left++;
                    else right--;
                }
            }
        }
        return ans;
    }
};