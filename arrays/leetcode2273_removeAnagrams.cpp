class Solution {
public:
    bool isAnagram(string s1, string s2){
        if(s1.length() != s2.length()) return false;
        vector<int> vec1(26, 0);
    
        for(int i=0;i<s1.length();i++){
            vec1[s1[i] - 'a']++;
            vec1[s2[i] - 'a']--;
        }

        for(auto &count : vec1)
        if(count != 0) return false;

        return true;
    }

    void stringReverse(vector<string>& vec){
        int i=0, j=vec.size()-1;
        while(i < j){
            swap(vec[i], vec[j]);
            i++;
            j--;
        }
    }

    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        int n = words.size();
       
        for(int i=n-1;i>0;i--){

            if( !isAnagram(words[i] , words[i-1]) )
            ans.push_back(words[i]);
        }
        ans.push_back(words[0]);

        stringReverse(ans);
        return ans;
    }
};
