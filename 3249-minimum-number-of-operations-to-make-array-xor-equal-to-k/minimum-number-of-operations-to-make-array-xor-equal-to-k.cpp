class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        int totalXor=0;
        for(auto &num: nums){
            totalXor^=num;
        }

        int finalXor=totalXor^k;  // no of 1 is no of operations

       return __builtin_popcount(finalXor); // count no of 1's in finalXor :::
    }
};