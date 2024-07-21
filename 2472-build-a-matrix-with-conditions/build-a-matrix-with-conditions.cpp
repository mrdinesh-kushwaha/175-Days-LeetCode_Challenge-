class Solution {
    vector<int> topoSort(vector<vector<int>>& adj, int k) {
        vector<int> indegree(k + 1, 0);
        for (int i = 1; i <= k; i++) {
            for (int edge : adj[i]) {
                indegree[edge]++;
            }
        }

        queue<int> q;
        vector<int> order;
        for (int i = 1; i <= k; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int curr = q.front(); q.pop();
            order.push_back(curr);

            for (int edge : adj[curr]) {
                indegree[edge]--;
                if (indegree[edge] == 0) {
                    q.push(edge);
                }
            }
        }

        return order.size() == k ? order : vector<int>();
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> rowGraph(k + 1), colGraph(k + 1);

        for (const vector<int>& row : rowConditions) {
            rowGraph[row[0]].push_back(row[1]);
        }
        for (const vector<int>& col : colConditions) {
            colGraph[col[0]].push_back(col[1]);
        }

        vector<int> rowOrder = topoSort(rowGraph, k);
        vector<int> colOrder = topoSort(colGraph, k);

        if (rowOrder.empty() || colOrder.empty()) return {};

        vector<int> rows(k + 1), cols(k + 1);
        for (int i = 1; i < k; i++) {
            rows[rowOrder[i]] = i;
            cols[colOrder[i]] = i;
        }

        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for (int i = 1; i <= k; i++) {
            matrix[rows[i]][cols[i]] = i;
        }

        return matrix;
    }
};