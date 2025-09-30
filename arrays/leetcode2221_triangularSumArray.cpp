class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp = nums;
        int j = 0;
        while(j != (n-1)){
        for(int i=0;i<n-1-j;i++){
            tmp[i] = (tmp[i] + tmp[i+1]) % 10;
        }
        j++;
        }
        return tmp[0];

    }
};
