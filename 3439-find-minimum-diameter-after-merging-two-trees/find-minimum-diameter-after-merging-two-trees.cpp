class Solution {
private:
    void build(vector<vector<int>>& adj, vector<vector<int>>& edges, int n){
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
    }
    void get(pair<int, int>& p, vector<vector<int>>& adj, int node, int dis, vector<int>& vis){
        int d = p.second;
        vis[node] = 1;
        if(dis>d){
            p.second = dis;
            p.first = node;
        }
        for(auto it: adj[node]){
            if(!vis[it]){
                get(p, adj, it, dis+1, vis);
            }
        }
    }
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size()+1;
        int m = edges2.size()+1;
        vector<vector<int>> adj1(n), adj2(m);

        build(adj1, edges1, n);
        build(adj2, edges2, m);

        //for first tree
        //this stores the farthest node from node 0, max dist of that node from 0
        vector<int>vis(n);
        pair<int, int> p1 = {-1, INT_MIN};
        get(p1, adj1, 0, 0, vis);
        //this stores the farthest node from the node farthest from 0, dia
        vis = vector<int>(n, 0);
        pair<int, int> p2 = {-1, INT_MIN};
        get(p2, adj1, p1.first, 0, vis);

        int d1 = p2.second;

        //now for the other tree
        p1 = {-1, INT_MIN};
        vis = vector<int>(m, 0);
        get(p1, adj2, 0, 0, vis);
        p2 = {-1, INT_MIN};
        vis = vector<int>(m, 0);
        get(p2, adj2, p1.first, 0, vis);

        int d2 = p2.second;
        if(edges1.empty()) d1 = 0;
        if(edges2.empty()) d2 = 0;

        return max({d1, d2, (d1 + 1) / 2 + (d2 + 1) / 2 + 1});
    }
};