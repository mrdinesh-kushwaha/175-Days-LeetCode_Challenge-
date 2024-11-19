class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        long long result=0;
        unordered_set<int>st;
        long long currWindowSum=0;
        int i=0;
        int j=0;

        while(j<n){
            // if deplicate exist
            while(st.count(nums[j])){
                currWindowSum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            currWindowSum +=nums[j];
            st.insert(nums[j]);
            // if length equal to the k:
            if(j-i+1 == k){
                result=max(result,currWindowSum);
                currWindowSum -=nums[i];
                st.erase(nums[i]);
                i++;
            }
            j++;
        }
        return result;
    }
};