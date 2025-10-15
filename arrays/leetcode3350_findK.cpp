class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        if(n == 2) return 1;

        vector<int> indxVec;
        indxVec.push_back(0);

        for(int i=1;i<n;i++){
            if(nums[i] <= nums[i-1])
             indxVec.push_back(i);
        }
        indxVec.push_back(n);


        int ans = 0;

        // for(int i=0;i<indxVec.size();i++){
        //    cout<<indxVec[i]<<" "<<endl;
        // }
        for(int i=1;i<indxVec.size();i++){
          
          int ans1 = (indxVec[i] - indxVec[i-1]) / 2;
          int ans2 = INT_MIN;
          if(i < (indxVec.size()-1) )
          ans2 = min(indxVec[i] - indxVec[i-1] , indxVec[i+1] - indxVec[i]);
        //   cout<<"ans1 "<<ans1<<" ans2 "<<ans2<<endl;
          ans = max(ans, max (ans1, ans2) );
        }
        return ans;
    }
};
