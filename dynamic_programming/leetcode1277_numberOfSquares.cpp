class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int sum = 0;

        for(int c = 0;c < n; c++){
            if(matrix[0][c] == 1){
                dp[0][c] = 1;
                sum++;
            } 
        }

        for(int r = 1;r < m; r++){
            if(matrix[r][0] == 1){
                dp[r][0] = 1;
                sum++;
            } 
        }


            
        for(int r=1;r<m;r++){
            for(int c=1;c<n;c++){
                if(matrix[r][c] == 1){
                    dp[r][c] = 1 + min({dp[r-1][c-1], dp[r][c-1], dp[r-1][c]});
                    sum += dp[r][c];
                }
            }
        }

        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return sum;
    }
};
