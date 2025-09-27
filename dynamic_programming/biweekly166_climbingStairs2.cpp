class Solution {
public:
    int climbStairs(int n, vector<int>& costs){
        vector<long long> dp(n + 1, 1e15);
        dp[0] = 0; 

        for (int i = 0; i <= n; i++) {
    
            for (int j = 1; j <= 3; j++) {
                int nextStep = i + j;
                if (nextStep <= n) {
                
                    int jumpCost = j * j;
                    int stepCost = (nextStep == 0) ? 0 : costs[nextStep - 1];
                    dp[nextStep] = min(dp[nextStep], dp[i] + stepCost + jumpCost);
                }
            }
        }

        return dp[n];
    }
};
