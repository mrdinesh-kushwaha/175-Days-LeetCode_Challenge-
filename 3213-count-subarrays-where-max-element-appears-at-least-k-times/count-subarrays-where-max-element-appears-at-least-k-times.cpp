class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        // Using Sliding Window Approach
        int maxE = *max_element(nums.begin(),nums.end());

        int n=nums.size();
        long long ans=0;
        int countMax=0;
        int i=0;
        int j=0;

        while(j<n){
            if(nums[j]==maxE){
                countMax++;
            }
            while(countMax>=k){
                ans+=n-j;
                
                if(maxE==nums[i]){
                    countMax--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};