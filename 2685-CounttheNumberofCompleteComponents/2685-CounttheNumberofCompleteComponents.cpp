// Last updated: 7/11/2026, 11:55:40 PM
1class Solution {
2    void dfs(int curr,int& nodes,int& edges,vector<vector<int>>& adj,vector<bool>& visited){
3        nodes++;
4        visited[curr] = true;
5        for(int& nbr: adj[curr]){
6            edges++;
7            if(!visited[nbr])
8                dfs(nbr,nodes,edges,adj,visited);
9        }
10    }
11public:
12    int countCompleteComponents(int n, vector<vector<int>>& edges) {
13        vector<vector<int>> adj(n);
14        for(auto& edge: edges){
15            adj[edge[0]].push_back(edge[1]);
16            adj[edge[1]].push_back(edge[0]);
17        }
18        int complete_components = 0;
19        vector<bool> visited(n,false);
20        for(int i=0;i<n;++i){
21            if(!visited[i]){
22                //Count nodes and edges for each component
23                int edges = 0;
24                int nodes = 0;
25                dfs(i,nodes,edges,adj,visited);
26                
27                if(edges==(nodes*(nodes-1)))
28                    complete_components++;
29            }
30        }
31        return complete_components;
32    }
33};