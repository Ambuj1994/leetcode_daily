class Solution {
public:
    int rows;
    vector<vector<int>> dp;
    vector<vector<int>> directions = {{1, 0}, {1, 1}};
    int solve(int r, int c,vector<vector<int>>& triangle){
            if(r >= rows) return 0;
            if(r == rows-1){
                return triangle[r][c];
            }

            if(dp[r][c] != -1e5) return dp[r][c];


        int down = triangle[r][c] + solve(r+1, c, triangle);
        int diag = triangle[r][c] + solve(r+1, c+1, triangle);

        return dp[r][c] = min(down, diag);        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        rows = triangle.size();
        dp.assign(rows+1, vector<int>(rows+1, -1e5));
        return solve(0, 0, triangle);
    }
};
