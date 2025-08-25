class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        map<int, vector<int>> mp;
        vector<int> ans;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
       
        bool flip = true;

        for(auto &it : mp){
           auto vec = it.second;
           if(flip){
            reverse(vec.begin(), vec.end());
           }
           flip = !flip;
           for(int i=0;i<vec.size();i++)
           ans.push_back(vec[i]);
        }
    
         return ans;
    }
};
