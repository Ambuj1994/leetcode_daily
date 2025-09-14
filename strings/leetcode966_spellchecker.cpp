class Solution {
public:
    string toLower(string str){
        for(auto &ch : str){
            if( (ch & (1 << 5)) == 0)
            ch |= ' ';
        }
        return str;
    }

    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    string generalise(string str){
        for(auto &ch : str){
            if(isVowel(ch))
            ch = '*';
        }
        return str;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exactList;
        unordered_map<string, string> capitalize;
        unordered_map<string, string> vowelize;

        vector<string> ans(queries.size(), "");

        for(auto& word : wordlist){
            exactList.insert(word);

            string str = word;
            str = toLower(str);
            if(capitalize.find(str) == capitalize.end()){
                capitalize[str] = word;
            }
            
            str = generalise(str);
            if(vowelize.find(str) == vowelize.end())
            vowelize[str] = word;

        }

        // for(auto &it : vowelize){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }

        for(int i=0;i<queries.size();i++){
            string word = queries[i];
            if(exactList.find(word) != exactList.end())
            ans[i] = word;
            else{
                string str = word;
                str = toLower(str);
                if(capitalize.find(str) != capitalize.end())
                ans[i] = capitalize[str];
                else{
                    str = generalise(str);
                    if(vowelize.find(str) != vowelize.end())
                    ans[i] = vowelize[str];
                }
            }
        }

        return ans;

    }
};
