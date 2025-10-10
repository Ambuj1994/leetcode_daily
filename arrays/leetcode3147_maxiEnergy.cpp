//Prefix sum with gap of k
//
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<bool> vis(n, 0);
        int maxi = -1e9;
        int i = 0;

        while(i < n){
            if(!vis[i]){
                int sum = 0;
                int j = i;

                while(j < n){
                    vis[j] = 1;
                    sum += energy[j];
                    sum = max(sum, energy[j]);
                    j = j + k;
                }
                maxi = max(maxi, sum);
            }
            i++;
        } 
        return maxi;


    }
};
