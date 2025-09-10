class Solution {
public:
    void findSubsets(vector<int>& nums, int i, vector<int>& subset, vector<vector<int>>& subsets, int n){
         if(i == n){
            subsets.push_back(subset);
            return;
         }
         
          //include
          subset.push_back(nums[i]);
          findSubsets(nums, i+1, subset, subsets, n);      
          subset.pop_back();

          //exclude -- we are iterating for duplicates in case of exclusion but not inclusion because if we want to exclude 2 we want to exclude all the occurrence of it
           while(i < n-1 && nums[i] == nums[i+1]) i++;
           findSubsets(nums, i+1, subset, subsets, n);   
         
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
       vector<vector<int>> subsets;
       vector<int> subset;
       findSubsets(nums, 0, subset, subsets, n);

       return subsets;
    }
};
