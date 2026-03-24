class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int size = nums.size();
        int ans = 0;
        int disTemp = INT_MAX; //For Distance need to Min so took Max

        for(int i=0;i<size-2;i++){
            int left = i+1;
            int right = size-1;
            int sum = 0;

            while(left<right){
                sum = nums[i]+nums[left]+nums[right];
                int distance = abs(sum-target); //checking who is closest

                if(distance < disTemp){
                    ans = sum;
                    disTemp = distance;
                }
                if(sum==target) return sum;
                else if(sum>target) right--;
                else left++;
            }
        }
        return ans;
    }
};