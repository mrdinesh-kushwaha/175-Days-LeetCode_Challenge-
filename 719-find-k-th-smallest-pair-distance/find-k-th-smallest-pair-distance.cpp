class Solution {
public:
int smallestDistancePair(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int low = 0, high = nums[n - 1] - nums[0];
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        
        // Count pairs with distance <= mid
        int count = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < n && nums[j] - nums[i] <= mid) {
                j++;
            }
            count += j - i - 1;
        }
        
        // If count of pairs <= mid is less than k, move right
        if (count < k) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    
    return low;
}

};