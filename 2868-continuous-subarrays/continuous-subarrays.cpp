
using namespace std;
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long count = 0;
        int left = 0;
        int n = nums.size();
        // Deques to maintain the max and min in the current window
        deque<int> maxDeque, minDeque;
        for (int right = 0; right < n; ++right) {
            // Maintain the max deque
            while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[right]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(right);
            // Maintain the min deque
            while (!minDeque.empty() && nums[minDeque.back()] >= nums[right]) {
                minDeque.pop_back();
            }
            minDeque.push_back(right);

            // Ensure the current window is valid
            while (nums[maxDeque.front()] - nums[minDeque.front()] > 2) {
                left++;
                // Remove indices that are out of the current window
                if (maxDeque.front() < left) {
                    maxDeque.pop_front();
                }
                if (minDeque.front() < left) {
                    minDeque.pop_front();
                }
            }
            // Count the number of valid subarrays ending at 'right'
            count += (right - left + 1);
        }
        return count;
    }
};