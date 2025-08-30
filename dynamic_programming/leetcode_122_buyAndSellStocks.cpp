class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int stocks(int i, int bucket, vector<int>& prices){
        if(i >= n) return 0;
        if(dp[i][bucket] != -1) return dp[i][bucket];



        int take, skip;
        if(bucket == 1){
           take = prices[i] + stocks(i+1, 1 - bucket, prices);
           skip = stocks(i+1, bucket, prices);
        }
        else{
            take = -prices[i] + stocks(i+1, 1 - bucket, prices);
            skip = stocks(i+1, bucket, prices);
        }
        return dp[i][bucket] = max(take, skip);
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.assign(n, vector<int>(2,-1));
        return stocks(0, 0, prices);
    }
};
