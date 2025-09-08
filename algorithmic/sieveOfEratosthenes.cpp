class Solution {
  public:
    
    vector<int> sieve(int n) {
       vector<bool> isPrime(n+1, true);
      
      isPrime[1] = false;
      for(int i=2; i<n;i++){
          if(isPrime[i]){
              for(int j=2; i*j <= n ;j++){
                  isPrime[i*j] = false;
              }
          }
      }
      vector<int> ans;
      for(int i=2;i<=n;i++){
          if(isPrime[i])
          ans.push_back(i);
      }
        return ans;
    }
};
