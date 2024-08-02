class Solution {
public:
    int countSeniors(vector<string>& s) {
        int ans = 0;
        for (const auto& ss : s) {
            int a1 = ss[11] - '0';
            int a2 = ss[12] - '0';
            if ((a1 * 10) + a2 > 60) {
                ans++;
            }
        }
        return ans;
    }
};