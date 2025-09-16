class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        int n = arrivals.size();
        int discarded = 0;
        unordered_map<int, int> numToCount;

        for(int i=0;i<n;i++){

            if(i >= w && arrivals[i - w] != -1){
                numToCount[arrivals[i - w]]--;
            }
               
 
            if(numToCount[arrivals[i]] == m){
                discarded++;
                arrivals[i] = -1;               
            }
            else{
                numToCount[arrivals[i]]++;
            }
        }

        return discarded;
    }
};
