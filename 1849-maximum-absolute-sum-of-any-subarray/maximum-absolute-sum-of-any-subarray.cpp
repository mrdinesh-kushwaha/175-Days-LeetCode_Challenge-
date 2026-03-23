class Solution {
public:
int minimumSub(vector<int>&nums){
    int bestEndingHere = nums[0];
    int ansSoFar = nums[0];

    for(int i=1;i<nums.size();i++){
        bestEndingHere = min(nums[i], bestEndingHere+nums[i]);
        ansSoFar = min(bestEndingHere, ansSoFar);
    }
    return abs(ansSoFar);
}
public:
int maximumSub(vector<int>&nums){
    int bestEndingHere = nums[0];
    int ansSoFar = nums[0];

    for(int i=1;i<nums.size();i++){
        bestEndingHere = max(nums[i], bestEndingHere+nums[i]);
        ansSoFar = max(bestEndingHere, ansSoFar);
    }
    return ansSoFar;
}
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans = max(maximumSub(nums), minimumSub(nums));
        return ans;
    }
};