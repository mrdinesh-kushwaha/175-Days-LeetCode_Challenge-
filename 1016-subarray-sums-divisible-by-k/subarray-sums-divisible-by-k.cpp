class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        unordered_map<int,int>prefix_sum;
        prefix_sum[0]=1; // base case:
        int sum=0;
        int ans=0;

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];

            int mod= sum % k;
            if(mod<0){
                mod= (mod % k + k); // convert negative reminder into possitive reminder
            }
            if(prefix_sum.find(mod)!=prefix_sum.end()){
                ans+=prefix_sum[mod]; //add freq of prefix_sum
            }
            prefix_sum[mod]++; // increase freq:
        }
        return ans;
    }
};