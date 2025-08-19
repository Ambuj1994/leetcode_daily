class Solution {
public:
    typedef long long ll;
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        ll zeroSoFar = 0;
        ll sum = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                zeroSoFar++;
            }
            else{
               sum += zeroSoFar * (zeroSoFar + 1) / 2;
               zeroSoFar = 0;
            }
        }
        if(nums[n-1] == 0) sum += zeroSoFar * (zeroSoFar + 1) / 2;
        return sum;
        
    }
};
