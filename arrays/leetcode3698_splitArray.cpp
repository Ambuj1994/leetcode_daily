
class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n), suffix(n);
        vector<bool> inc(n), dec(n);


        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) prefix[i] = prefix[i-1] + nums[i];

 
        suffix[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; i--) suffix[i] = suffix[i+1] + nums[i];

    
        inc[0] = true;
        for (int i = 1; i < n; i++) {
            inc[i] = inc[i-1] && (nums[i] > nums[i-1]);
        }

      
        dec[n-1] = true;
        for (int i = n-2; i >= 0; i--) {
            dec[i] = dec[i+1] && (nums[i] > nums[i+1]);
        }

        long long ans = LLONG_MAX;
        for (int i = 0; i < n-1; i++) {
            if (inc[i] && dec[i+1]) {
                ans = min(ans, llabs(prefix[i] - suffix[i+1]));
            }
        }

        return ans == LLONG_MAX ? -1 : ans;
    }
};

