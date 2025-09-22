class Solution {
public:
    int n;
    vector<int> dp;
    int solve(int idx, int k, vector<int>& nums){
        if(idx >= k+1) return 0;

        if(dp[idx] != -1) return dp[idx];
        
        int take = nums[idx] + solve(idx + 2, k, nums);
        int skip = solve(idx + 1, k, nums);

        return dp[idx] = max(take, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        dp.assign(n+1, -1);
        int steal1 = solve(0, n-2, nums);

        dp.assign(n+1, -1);
        int steal2 = solve(1, n-1, nums);

        return max(steal1, steal2);
    }
};
