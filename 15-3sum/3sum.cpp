class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //Extended Version Sum
        //nums[i]+nums[left]+nums[right]=0
        //nums[left]+nums[right] = -nums[i] -> let's suppose target
        //nums[left] + nums[right] = target

        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>>res; // for result

        for(int i=0;i<nums.size()-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int left = i+1;
            int right = nums.size()-1;
            int target = -nums[i];
            int pointerSum = 0;

            while(left<right){
                pointerSum = nums[left]+nums[right];
                vector<int>temp;
                if(pointerSum == target){
                    //store
                    res.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;

                    while(left<n && nums[left] == nums[left-1]) left++;
                    while(right>=0 && nums[right] == nums[right+1]) right--;
                }
                else if(target > pointerSum) left++;
                else right--; 
            }
        }
        return res;
    }
};