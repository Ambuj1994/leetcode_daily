class Solution {
  public:
    bool dfs(int currNode, int currColor,vector<vector<int>>& adj,vector<int>& color){
        color[currNode] = currColor;
        
        for(auto &adjNode : adj[currNode]){
            
               if(color[adjNode] == currColor)
               return false; 
               
               if(color[adjNode] == -1 && !dfs(adjNode,1-currColor,adj,color))            
               return false; 
            
        }
        return true;
    }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> color(V, -1);
        for(int i=0;i<V;i++){
            if(color[i] == -1){
                if(!dfs(i, 0, adj, color))
                return false;
            }
        }
        return true;
    }
};
