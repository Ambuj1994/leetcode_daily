class Solution {
  public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj, stack<int>& st){
        if(vis[node]) return;
        
        vis[node] = 1;
        for(auto &adjNode : adj[node]){
            if(!vis[adjNode]){
              dfs(adjNode, vis, adj, st);
              st.push(adjNode);               
            }
        }
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
        }
        
        vector<int> vis(V,0);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adj,st);
                st.push(i);
            }
        }
        
        vector<int> ans;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            ans.push_back(node);
        }
        return ans;
    }
};
