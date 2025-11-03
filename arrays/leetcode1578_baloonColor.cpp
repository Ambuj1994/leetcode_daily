class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = neededTime.size();
        if(n == 1) return 0;
 

        int prev = 0;
        int ans = 0;
        for(int i=1;i<n;i++){
           if(colors[i] == colors[prev]){
              if(neededTime[prev] < neededTime[i]){
                ans += neededTime[prev];
                prev = i;
              }
              else{
                ans += neededTime[i];
              }
           }
           else{
            prev = i;
           }
        }
        return ans;
    }
};
