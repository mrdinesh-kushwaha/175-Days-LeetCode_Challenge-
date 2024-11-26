class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);

        for (const auto& d : edges) {
            indegree[d[1]]++;
        }

        int ans = -1;
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                count++;
                ans = i;
            }
        }

        return count > 1 ? -1 : ans;
    }
};