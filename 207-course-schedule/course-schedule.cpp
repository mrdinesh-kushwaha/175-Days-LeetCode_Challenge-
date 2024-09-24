class Solution {
    private: 
    bool topoSortBFS(int n, unordered_map<int,list<int>>& adjList){
        //find indegree
        //put all in queue indegree=0;
        //BFS Logic
        vector<int>ans;
        queue<int>q;
        unordered_map<int,int>indegree;
        //find indegree
        for(auto node:adjList){
            int src=node.first;
            for(auto nbr:node.second){
                indegree[nbr]++;
            }
        }
        //put all in queue indegree==0
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        //BFS Logic
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            //remove node from indegree
            for(auto nbr:adjList[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }

        if(ans.size()==n) return true; // means topoSort is valid
        else return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // this solve using topologicalsort, because it has dependencies and DAG
        // convert into the graph
        unordered_map<int,list<int>>adjList;
        for(auto& node: prerequisites){
            int u=node[0];
            int v=node[1];
            adjList[v].push_back(u);
        }
        bool ans=topoSortBFS(numCourses,adjList);

        return ans;
    }
};