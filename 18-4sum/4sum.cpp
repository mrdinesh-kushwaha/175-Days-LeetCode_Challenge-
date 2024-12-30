class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
         // Solve this problem using the 3Sum problem Approach
        // using two pointer approach to solve this problem

        int n = nums.size();
        sort(begin(nums),end(nums));
        vector<vector<int>>ans; // for storing the result
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue ; // for remove deplicate
            for(int j=i+1;j<n;j++){
                if(j != i+1 && nums[j]==nums[j-1]) continue;// for remove deplicate

                //Now apply Two Pointer Approach
                int left = j+1;
                int right = n-1;
                while(left<right){
                    long long sum = nums[i];
                    sum+=nums[j];
                    sum+=nums[left];
                    sum+=nums[right];
                    if(sum==target){
                        vector<int>temp={nums[i],nums[j],nums[left],nums[right]};
                        ans.push_back(temp);
                        left++,right--;

                        //Now also Need to remove deplicate
                        while(left<right && nums[left]==nums[left-1])left++;
                        while(left<right && nums[right]==nums[right+1])right--;
                    }
                    else if(sum > target) right--;
                    else left++;
                }
            }
        }
        return ans;
    }
};