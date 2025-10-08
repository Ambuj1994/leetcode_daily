class Solution {
public:
    int lowerBound(vector<int>& potions,long long key){
        int ans =  -1;
        int l = 0, r = potions.size() - 1;
        while(l <= r){
            int mid = l + ((r - l) >> 1);
            if(potions[mid] >= key){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        if(ans == -1)return -1;
       return ans;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> result;
        int n = potions.size();
        sort(potions.begin(), potions.end());

        for(int i=0;i<spells.size();i++){
           long long key = ceil( (double)success / spells[i]);
         
           int idx = lowerBound(potions, key);
         

           if(idx == -1) 
              result.push_back(0);
           else
              result.push_back(n - idx);
        }
        return result;
    }
};
