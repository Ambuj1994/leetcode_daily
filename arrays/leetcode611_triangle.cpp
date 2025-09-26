class Solution {
public:
    int binarySearch(const vector<int>& nums, int l, int r, int target) {
        int k = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target) {
                k = mid;         // mid is valid
                l = mid + 1;     // try to go right
            } else {
                r = mid - 1;     // go left
            }
        }
        return k;
    }

    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        sort(nums.begin(), nums.end());
        int count = 0;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) 
                continue;  
            
            for (int j = i + 1; j < n; ++j) {

                int sum = nums[i] + nums[j]; //sum of two sides
                int k = binarySearch(nums, j + 1, n - 1, sum);
                if (k != -1) 
                    count += (k - j);
            }
        }

        return count;
    }
};

