//T.C. = O(n)
//S.C. = O(1)

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       int n = nums.size();
       if(n == 1) return 0;
       int countOfZero = 0;
       int ans = 0;
       int l=0,r=0;
       while(r < n){
        if(nums[r] == 0) countOfZero++;

          while(countOfZero > 1 && l <= r){
             if(nums[l] == 0) countOfZero--;

             l++;
          }

          ans = max(ans, r - l);
          r++;
       }
       return ans;
    }
};
