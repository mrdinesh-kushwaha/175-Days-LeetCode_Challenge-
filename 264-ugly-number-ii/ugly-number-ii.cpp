class Solution {
public:
int nthUglyNumber(int n) {
    priority_queue<long, vector<long>, greater<long>> pq; // Min-heap
    set<long> seen; // To avoid duplicates

    pq.push(1); // Start with the first ugly number
    seen.insert(1);

    long currentUgly = 1;

    // Directions to multiply by 2, 3, and 5
    long factors[3] = {2, 3, 5};

    for (int i = 1; i < n; i++) {
        currentUgly = pq.top(); 
        pq.pop(); 

        for (int j = 0; j < 3; j++) {
            long newUgly = currentUgly * factors[j];
            if (seen.find(newUgly) == seen.end()) {
                pq.push(newUgly);
                seen.insert(newUgly);
            }
        }
    }

    return (int) pq.top(); 
    }
};