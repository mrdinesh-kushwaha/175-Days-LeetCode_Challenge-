class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 0;
        int temp = INT_MAX;
        sort(nums.begin(),nums.end());
        int size = nums.size();

        for(int i=0;i<size-2;i++){
            int left = i+1;
            int right = size-1;
            int sum = 0;

            while(left<right){
                sum = nums[i]+nums[left]+nums[right];
                int diffTarget = abs(sum-target);

                if(diffTarget<temp){
                    ans = sum;
                    temp=diffTarget;
                }
                if(sum==target) return sum;
                else if(sum>target) right--;
                else left++;
            }
        }
        return ans;
    }
};