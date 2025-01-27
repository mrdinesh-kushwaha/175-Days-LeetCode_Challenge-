class Solution {
public:
void dfs (int node, set<int>&v, vector<vector<int>>&adj , vector<int>&vis) {
    vis[node] = 1;
    v.insert(node);
    for (auto i : adj[node]) {
        if (vis[i] == 0) dfs(i,v,adj,vis);
    }
}
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& p,
    vector<vector<int>>& pq) {
        if (p.size() == 0) {
            vector<bool>qq;
            for (auto i:pq) qq.push_back(false);
            return qq;
        }
        vector<vector<int>>adj(n);
        for (auto i : p) {
            int a = i[0];
            int b = i[1];
            adj[a].push_back(b);
        }
        vector<set<int>>mat;
        for (int i = 0; i < n; i++) {
            set<int>v;
            vector<int>vis(n,0);
            dfs(i , v , adj , vis);
            mat.push_back(v);
        }
        vector<bool>ans;
        for (auto i : pq) {
            int a = i[0];
            int b = i[1];
            if (mat[a].find(b) != mat[a].end()) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};