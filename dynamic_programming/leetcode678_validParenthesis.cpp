class Solution {
public:
    int n;
    vector<vector<int>> dp;
    bool solve(int i, string& s, int open){
        if(open < 0) return false;
        if(i == n){
            if(open == 0) 
            return true;
            else
            return false;
        }

        bool openCheck, closeCheck, normal;
        if(dp[i][open] != -1) return dp[i][open];

        if(s[i] == '('){
           return solve(i+1, s, open+1); 
        }

        if(s[i] == ')'){
         return solve(i+1, s, open-1); 
        }

        if(s[i] == '*'){
          openCheck = solve(i+1, s, open+1);
          closeCheck = solve(i+1, s, open-1);
          normal = solve(i+1, s, open);
        }
     return dp[i][open] = (openCheck || closeCheck || normal);
    
    }
    bool checkValidString(string s) {
        n = s.length();
        dp.assign(n+1, vector<int>(n+1, -1));
        int open = 0;
        return solve(0, s, open);
    }
};
