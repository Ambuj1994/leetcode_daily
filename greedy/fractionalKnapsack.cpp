class Solution {
  public:
  
    static bool comparator(vector<int>& item1, vector<int>& item2) {
        double r1 = (double)item1[0] / item1[1];
        double r2 = (double)item2[0] / item2[1];
        return r1 > r2;  // sort in decreasing order
    }
    
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<vector<int>> valWt(n, vector<int>(2));
        for(int i=0;i<n;i++){
            valWt[i][0] = val[i];
            valWt[i][1] = wt[i];
        }
        
        sort(valWt.begin(), valWt.end(), comparator);
        
        double profit = 0;
        for(auto &it : valWt){
           int cost = it[0];
           int weight = it[1];
           
           if(weight <= capacity){
               capacity -= weight;
               profit = profit + cost;
           }
           else{
               profit += (double)(cost)/weight * (capacity);
               break;
           }
        }
        return profit;
    }
};

