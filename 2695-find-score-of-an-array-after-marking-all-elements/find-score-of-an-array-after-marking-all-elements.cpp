class Solution {
public:
long long findScore(vector<int>& nums) {
    // int n = nums.size();
    // long long score = 0;

    // // Min-heap to store (value, index) pairs
    // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // // Fill the priority queue with all elements
    // for (int i = 0; i < n; i++) {
    //     pq.push({nums[i], i});
    // }

    // vector<bool> marked(n, false); // Track marked indices

    // while (!pq.empty()) {
    //     auto [val, idx] = pq.top();
    //     pq.pop();

    //     // If already marked, skip this element
    //     if (marked[idx]) continue;

    //     // Add the value to the score
    //     score += val;
    //     marked[idx] = true; // Mark the current element

    //     // Mark adjacent elements if they exist
    //     if (idx - 1 >= 0) marked[idx - 1] = true;
    //     if (idx + 1 < n) marked[idx + 1] = true;
    // }

    // return score;

    //******* Optimise this code:

       int n = nums.size();
    long long score = 0;

    // Min-heap to store (value, index) pairs
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Fill the priority queue with all elements
    for (int i = 0; i < n; i++) {
        pq.push({nums[i], i});
    }

    vector<bool> marked(n, false); // Track marked indices

    while (!pq.empty()) {
        auto [val, idx] = pq.top();
        pq.pop();

        // If already marked, skip this element
        if (marked[idx]) continue;

        // Add the value to the score
        score += val;
        marked[idx] = true; // Mark the current element

        // Mark adjacent elements if they exist
        if (idx - 1 >= 0) marked[idx - 1] = true;
        if (idx + 1 < n) marked[idx + 1] = true;
    }

    return score;
}

};