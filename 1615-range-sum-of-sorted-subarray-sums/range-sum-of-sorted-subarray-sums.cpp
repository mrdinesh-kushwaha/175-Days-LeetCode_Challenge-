class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int mod=1e9+7;
        int num=n*(n+1)/2;
        vector<int>vec;
        int arrn= nums.size();
        for(int i=0;i<arrn;i++){
            int sum=0;
            for(int j=i;j<arrn;j++){
                sum+=nums[j];
                vec.push_back(sum);
            }
        }
        sort(vec.begin(),vec.end());

        int ans=0;
        for(int i=left-1;i<right;i++){
            ans=(ans % mod +vec[i]) % mod;
        }
        return ans;
    }
};