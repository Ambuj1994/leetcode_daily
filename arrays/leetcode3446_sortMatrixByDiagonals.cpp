class Solution {
public:
    void lowerHalf(vector<vector<int>>& grid){
          int n = grid.size();

          for(int i=0;i<n;i++){
            vector<int> temp;
            int r=i, c=0;
            while(r<n && c<n){
                temp.push_back(grid[r][c]);
                r++;
                c++;
            }
            sort(temp.begin(), temp.end(),greater<int>());
            r=i, c=0;
            for(int j=0;j<temp.size();j++){
               grid[r][c] = temp[j];
               r++;
               c++;
            }
          }  
    }

    void upperHalf(vector<vector<int>>& grid){
        int n = grid.size();
    
        for(int i=1;i<n;i++){
            int r=0,c=i;
            vector<int> temp;
            while(r<n && c<n){             
                temp.push_back(grid[r][c]);
                r++;
                c++;
            }
            sort(begin(temp),end(temp));
            r=0,c=i;
            for(int j=0;j<temp.size();j++){
               grid[r][c] = temp[j];
               r++;
               c++;
            }            
        }
    }

    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        lowerHalf(grid);
        upperHalf(grid);

        return grid;

    }
};
