class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int mask = 0;
        int count = 0;
        for(auto &ch : brokenLetters){
            mask |= (1 << (ch - 'a') ); 
        }
    

        bool broken = false;

        int n = text.size();
        for(int i=0; i<n; i++){
            char ch = text[i];
            if( (ch != ' ') && (((mask & (1 << (ch - 'a'))) != 0)) ){
                broken = true;
            }

            if(ch == ' ' || i == n-1){
                
                if(!broken)
                count++;
                else
                broken = false;
            } 
        }
        return count;
    }
};
