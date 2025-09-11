//Approach 1 - Normal Sort
//TC = O(nlogn)
//SC = O(n)
class Solution {
    bool isVowel(char ch){
        return (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' ||ch == 'U' || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

public:
    string sortVowels(string s) {
        string vowel;
        for(auto &ch : s){
            if(isVowel(ch))
            vowel += ch;
        }
        sort(begin(vowel), end(vowel));

        int j=0;
        for(int i=0;i<s.length();i++){
            if(isVowel(s[i])){
                s[i] = vowel[j++];
            }
        }
        return s;
    }
};

/*
Difference between `vowel = vowel + ch;` and `vowel += ch;` in C++:

- `vowel = vowel + ch;`
  Creates a new temporary string each time (copies old string, appends ch, reassigns).
  Cost: O(n) per append → inefficient, can cause MLE/TLE.

- `vowel += ch;`
  Appends directly to the existing buffer (in-place, occasional reallocation).
  Cost: Amortized O(1) per append → efficient and preferred.

Key: Both give the same result, but `+=` is much faster and memory-friendly.
*/


//Approach 2 - Counting Sort or Frequency Array
class Solution {
public:
    string sortVowels(string s) {
        vector<int> freq(128, 0);
        vector<bool> isVowel(128, false);

        string vowels = "aeiouAEIOU";
        for (char v : vowels) {
            isVowel[v] = true;
        }

        for (char c : s) {
            if (isVowel[c]) {
                freq[c]++;
            }
        }

        string order = "AEIOUaeiou";
        int pos = 0;

        for (char &c : s) {
            if (isVowel[c]) {
                while (pos < order.size() && freq[order[pos]] == 0) {
                    pos++;
                }
                c = order[pos];
                freq[order[pos]]--;
            }
        }

        return s;
    }
};

