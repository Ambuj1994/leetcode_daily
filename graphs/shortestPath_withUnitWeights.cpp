class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
      vector<vector<int>> adj(V);
      vector<int> indegree(V,0);
      
       for(auto &edge : edges){
           int u = edge[0];
           int v = edge[1];
           
           adj[u].push_back(v);
           indegree[v]++;
       }
       
       queue<int> q;
       vector<int> ans;
       for(int i=0;i<V;i++){
           if(indegree[i] == 0){
               q.push(i);
               ans.push_back(i);
           }
           
       }
       
       while(!q.empty()){
           int node = q.front();
           q.pop();
           for(auto &adjNode : adj[node]){
               indegree[adjNode]--;
               
               if(indegree[adjNode] == 0){
                   q.push(adjNode);
                   ans.push_back(adjNode);
               }
               
           }
       }
       return ans;
       
    }
};
