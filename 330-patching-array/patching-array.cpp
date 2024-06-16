class Solution {
public:
    int minPatches(vector<int>& nums, int n) {

        long long maxReach = 0;
        int noPatch = 0;
        int i = 0;
        while (maxReach < n) {

            if (i < nums.size() && nums[i] <= maxReach + 1) {
                maxReach += nums[i];
                i++; // do nothing
            }

            else {
                maxReach += (maxReach + 1); // need to add patches...
                noPatch++;
            }
        }
        return noPatch;
    }
};