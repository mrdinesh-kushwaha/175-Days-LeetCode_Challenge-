class Solution {
public:
vector<int> decrypt(vector<int>& code, int k) {
    int n = code.size();
    vector<int> vec(n, 0); // Initialize vec with size n and all elements set to 0

    if (k > 0) {
        for (int i = 0; i < n; i++) {
            int sum = 0;
            int steps = k; // Store the original value of k
            int p = i + 1;
            while (steps--) {
                if (p == n) {
                    p = 0; // Wrap around to the beginning
                }
                sum += code[p++];
            }
            vec[i] = sum;
        }
    } else if (k < 0) {
        for (int i = 0; i < n; i++) {
            int sum = 0;
            int steps = abs(k); // Store the absolute value of k
            int p = i - 1;
            while (steps--) {
                if (p < 0) {
                    p = n - 1; // Wrap around to the end
                }
                sum += code[p--];
            }
            vec[i] = sum;
        }
    }
    // For k == 0, vec remains initialized to 0
    return vec;
}

};