class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        unordered_map<int,int>prefix_sum_Freq;
        prefix_sum_Freq[0]=1; // base case:
        int sum=0;
        int ans=0;

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];

            int mod= sum % k;
            if(mod<0){
                mod= (mod % k + k); // convert negative reminder into possitive reminder
            }
            if(prefix_sum_Freq.find(mod)!=prefix_sum_Freq.end()){
                ans += prefix_sum_Freq[mod]; //add freq of prefix_sum
            }
            prefix_sum_Freq[mod]++; // increase freq:
        }
        return ans;
    }
};