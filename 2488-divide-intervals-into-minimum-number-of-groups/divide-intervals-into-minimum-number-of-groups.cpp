class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end()); // Step 1: Sort intervals based on starting time
        priority_queue<int, vector<int>, greater<int>> pq; // Step 2: Create a min-heap (priority queue)
        
        pq.push(intervals[0][1]); // Step 3: Push the end time of the first interval into the heap
        
        for (int i = 1; i < intervals.size(); i++) { // Step 4: Iterate through the rest of the intervals
            if (intervals[i][0] > pq.top()) { // Step 5: If the start time of the current interval is greater than the smallest end time in the heap
                pq.pop(); // Step 6: Remove the smallest end time (a group has finished)
            }
            pq.push(intervals[i][1]); // Step 7: Add the end time of the current interval to the heap
        }
        
        return pq.size(); // Step 8: The size of the heap represents the minimum number of groups needed
    }
};
