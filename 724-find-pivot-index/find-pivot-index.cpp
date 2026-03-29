class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // using excluding i prefix and suffix approach
        int n = nums.size();
        vector<int>prefix(n,0);
        vector<int>suffix(n,0);

        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] + nums[i-1];
        }

        for(int i=n-2;i>=0;i--){
            suffix[i] = suffix[i+1] + nums[i+1];
        }

        for(int i=0;i<n;i++){
            if(prefix[i]==suffix[i]) return i;
        }
        return -1;
    }
};