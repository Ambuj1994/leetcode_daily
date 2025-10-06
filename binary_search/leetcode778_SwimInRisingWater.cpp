//LEARNING - If statement has Maximize the Min or Minimize the max , binary search on answer can be the probable solution
//This question can be done with dijkastra also
class Solution {
public:
    int n;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    bool reachable(int r, int c, int mid, vector<vector<int>>& grid, vector<vector<bool>>& vis){
        if(r < 0 || r >= n || c < 0 || c >= n || vis[r][c] || mid < grid[r][c])
        return false;

        if(r == n-1 && c == n-1){
            vis[r][c] = true;
            return true;
        }

        vis[r][c] = true;
        bool result = false;
        for(auto &dir : directions){
            int r_ = r + dir[0];
            int c_ = c + dir[1];
            result |= reachable(r_, c_, mid, grid, vis);
        }
        return result;
    }
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int r = n * n - 1;
        int l = grid[0][0];
        int ans;
        while(l <= r){
            int mid = l + (r - l) / 2;
            vector<vector<bool>> vis(n, vector<bool>(n, false));
            if(reachable(0, 0, mid, grid, vis)){
               ans = mid;
               r = mid - 1;
            }
            else
               l = mid + 1;
        }

        return ans;
    }
};
