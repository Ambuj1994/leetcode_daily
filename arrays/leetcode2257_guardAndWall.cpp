/*
 * LEARNING : 
 *Here I have learnt importance of clear writing
 like taking variable GUARDED UNGUARDED WALL GUARD and assigning int value to them.
 No char is used, simple variable is used
 */

class Solution {
public:
    const int GUARDED = 0;
    const int UNGUARDED = 1;
    const int GUARD = 2;
    const int WALL = 3;

    bool isSafe(int r, int c, int m, int n){
        return (r >= 0  && c >= 0 && r < m && c < n);
    }

    void solve(vector<vector<int>> &grid, int r, int c, int m, int n, char dir){
        if(!isSafe(r, c, m, n) || grid[r][c] == WALL || grid[r][c] == GUARD) return;

        grid[r][c] = GUARDED;
        if(dir == 'D')solve(grid, r + 1, c, m, n, 'D');
        if(dir == 'U')solve(grid, r - 1, c, m, n, 'U');
        if(dir == 'R')solve(grid, r, c + 1, m, n, 'R');
        if(dir == 'L')solve(grid, r, c - 1, m, n, 'L');
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {

        vector<vector<int>> grid(m, vector<int>(n, UNGUARDED));
        for(auto &guard : guards){
            int r = guard[0];
            int c = guard[1];
            grid[r][c] = GUARD;
        }

        for(auto &wall : walls){
            int r = wall[0];
            int c = wall[1];
            grid[r][c] = WALL;
        }

        for(auto &guard : guards){
           int r = guard[0];
           int c = guard[1];
           solve(grid,r+1,c,m,n,'D');
           solve(grid,r-1,c,m,n,'U');
           solve(grid,r,c+1,m,n,'R');
           solve(grid,r,c-1,m,n,'L');
        }

        int count = 0;
        for(int i=0;i < m;i++){
            for(int j=0;j < n;j++){
                if(grid[i][j] == UNGUARDED) count++;
            }
        }

        return count;
    }
};
