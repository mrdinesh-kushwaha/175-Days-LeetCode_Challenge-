class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

  vector<vector<pair<int, int>>> graph(n);  
    for (const auto& edge : edges) {  
        int from = edge[0], to = edge[1], weight = edge[2];  
        graph[from].emplace_back(to, weight);  
        graph[to].emplace_back(from, weight);  
    }  

    int cityWithMinReachable = -1;  
    int minReachableCount = numeric_limits<int>::max();  

    for (int i = 0; i < n; ++i) {  
        // Use Dijkstra's algorithm to find all reachable cities from city i  
        vector<int> dist(n, numeric_limits<int>::max());  
        dist[i] = 0;  
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  
        pq.emplace(0, i); // (distance, city)  

        while (!pq.empty()) {  
            auto [currDist, currCity] = pq.top();  
            pq.pop();  

            // If the current distance is greater than the threshold, skip  
            if (currDist > distanceThreshold) continue;  

            for (const auto& [neighbor, weight] : graph[currCity]) {  
                int newDist = currDist + weight;  
                if (newDist < dist[neighbor]) {  
                    dist[neighbor] = newDist;  
                    pq.emplace(newDist, neighbor);  
                }  
            }  
        }  

        // Count reachable cities within the distance threshold  
        int reachableCount = 0;  
        for (int j = 0; j < n; ++j) {  
            if (dist[j] <= distanceThreshold) {  
                reachableCount++;  
            }  
        }  

        // Determine if we found a better city  
        if (reachableCount < minReachableCount ||   
            (reachableCount == minReachableCount && i > cityWithMinReachable)) {  
            minReachableCount = reachableCount;  
            cityWithMinReachable = i;  
        }  
    }  

    return cityWithMinReachable;  
        
    }
};