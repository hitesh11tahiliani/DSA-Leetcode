//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    
private:
    bool dfs(int node, int parent, int vis[], vector<int> adj[]){
        vis[node] =1;
        
        // visit adjacent nodes
        for (auto adjacentNode : adj[node]){
            // unvisited adjacent node
            if(!vis[adjacentNode]){
                if(dfs(adjacentNode, node, vis, adj)==true)
                    return true;
            }
            // visited node but not a parent node
            else if(adjacentNode != parent)
                return true;
        }
        return false;
    }
    
  public:
  
//   DFS METHOD 
  
  bool isCycle(int V, vector<int> adj[]) {
    int vis[V] = {0};
      
    //   for graph with connected components 
    for (int i=0; i<V; i++){
        if(!vis[i]){
            if(dfs(i, -1, vis, adj)==true)
                return true;
        }
    }
    return false;
  }
  
    
    // // BFS cycle detection
    // bool BFS(int i, vector<int> &vis, vector<int> adj[])
    // {
    //     queue<pair<int, int>> q;
        
    //     q.push({i ,-1});
    //     vis[i]=1;
        
    //     while(!q.empty())
    //     {
    //         int node = q.front().first;
    //         int par = q.front().second;
    //         q.pop();
        
    //         for(auto it : adj[node])
    //         {
    //             if(!vis[it])
    //             {
    //                 q.push({it, node});
    //                 vis[it]=1;
    //             }
    //             else if(par!=it)
    //             {
    //                 return true;    //cycle found in this graph component!
    //             }
    //         }
            
    //     }
        
    //     return false;   //No cycle in this graph component
        
    // }
    
    // // BFS Function to detect cycle in an undirected graph.
    // bool isCycle(int V, vector<int> adj[]) 
    // {
    //     vector<int> vis(V, 0);
        
    //     for(int i=0; i<V; i++)
    //     {
    //         if(!vis[i])
    //         {
    //             if(BFS(i, vis, adj)) return true;
    //         }
    //     }
        
    //     return false;
    // }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends