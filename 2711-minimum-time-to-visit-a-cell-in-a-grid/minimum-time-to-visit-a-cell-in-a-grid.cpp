class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<>> pq;
        pq.emplace(0, make_pair(0,0));
        int m  = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, -1));
        visited[0][0] = 0;
        vector<pair<int,int>> dir = {{1,0}, {0,1}, {-1, 0}, {0,-1}};
        if(grid[1][0] > 1 && grid[0][1] > 1) {
            return -1;
        }
        while(!pq.empty()) {
            auto [time, p] = pq.top();
            pq.pop();
            if(p.first == m-1 && p.second == n-1) {
                return time;
            }
            int i = p.first;
            int j = p.second;
            for(int ptr = 0;ptr<4;ptr++) {
                int resi = i + dir[ptr].first;
                int resj = j + dir[ptr].second;
                if(resi>=0 && resj>=0 && resi < m && resj<n) {
                    int timet = max(time+1, grid[resi][resj] + ((time%2 == grid[resi][resj]%2) ? 1 : 0));
                    if((visited[resi][resj] == -1 || visited[resi][resj] > timet)) {
                        visited[resi][resj] = timet;
                        pq.emplace(timet, make_pair(resi, resj));
                    }
                }
            }
        }
        return -1;
    }
};