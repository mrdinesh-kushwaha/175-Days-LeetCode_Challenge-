class Solution {
public:
    long long maximumSubarraySum(vector<int>& n, int k) {
   long long m = 0, s = 0;
    int l = 0;
    unordered_map<int, int> c;
    for (int r = 0; r < n.size(); r++) {
        c[n[r]]++;
        s += n[r];
        while (c[n[r]] > 1 || r - l + 1 > k) {
            c[n[l]]--;
            s -= n[l];
            l++;
        }
        if (r - l + 1 == k) m = max(m, s);
    }
    return m;

    }
};