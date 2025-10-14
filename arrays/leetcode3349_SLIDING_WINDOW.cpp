class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        unordered_set<int> st;
        int n = nums.size();

        int i = 0, j = 1;
        while (j < n) {
         
            if (nums[j] <= nums[j - 1]) {
                i = j;
            }

            
            if (j - i + 1 == k) {
                
                if (st.count(i - k)) return true;

              
                st.insert(i);

            
                i++;
            }

            j++;
        }

        
        if (k == 1 && n >= 2) return true;

        return false;
    }
};

