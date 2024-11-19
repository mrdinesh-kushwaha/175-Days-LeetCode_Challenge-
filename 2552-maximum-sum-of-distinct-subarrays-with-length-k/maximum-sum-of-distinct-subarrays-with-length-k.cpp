class Solution {
public:
   long long maximumSubarraySum(vector<int>& a, int k) {
  long long m = 0, s = 0;
    int l = 0;
    unordered_map<int, int> b;
    for (int r = 0; r < a.size(); r++) {
        b[a[r]]++;
        s += a[r];
        while (b[a[r]] > 1 || r - l + 1 > k) {
            b[a[l]]--;
            s -= a[l++];
        }
        if (r - l + 1 == k) m = max(m, s);
    }
    return m;

    }
};