class Solution {
public:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int maxFreqSum(string s) {
        vector<int> freq(26, 0);
        int conso = 0;
        int vowel = 0;

        for(auto &ch : s){
            freq[ch - 'a']++;

            if(isVowel(ch)){
                vowel = max(vowel, freq[ch - 'a']);
            }
            else{
                conso = max(conso, freq[ch - 'a']);
            }
        }
        cout<<"c : "<<conso<<" v : "<<vowel;
        
        return conso + vowel;
    }
};
