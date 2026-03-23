class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //Using Kadance Algorithm
        //At each index 3 option
        //1- curr i ko lekar alag subarray banao
        //2- i*minProd
        //3- i*maxProd

        int minProd = nums[0];
        int maxProd = nums[0];
        int res = nums[0];

        for(int i=1;i<nums.size();i++){
            int curr = nums[i];
            int v1 = nums[i]*minProd;
            int v2 = nums[i]*maxProd;

            minProd = min(curr, min(v1,v2));
            maxProd = max(curr, max(v1,v2));

            res = max(res, max(minProd, maxProd));
        }
        return res;
    }
};