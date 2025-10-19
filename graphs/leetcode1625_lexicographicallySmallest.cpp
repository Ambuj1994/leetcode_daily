/*
 Here I learnt :
 1) How to rotate a string , using 3 reverse function
 2) A class of pattern where the problem:
    ->Asks about a number or word.
    ->Each digit or character can be changed in some way.
    ->We have to reach a target word/number in minimimum number of operations
      or, find the max/min of those states/nodes often leads to finite number of states.

Solution : It becomes a graph traversal problem so use DFS/BFS.
*/
      
    

class Solution {
public:
    void rotate(string &s, int b) {
        reverse(begin(s), end(s));
        reverse(begin(s), begin(s) + b);
        reverse(begin(s) + b, end(s));
    }

    string findLexSmallestString(string s, int a, int b) {
        string smallestString = s;

        unordered_set<string> visited;
        queue<string> que;
        que.push(s);
        visited.insert(s);

        while(!que.empty()) {
            string curr = que.front();
            que.pop();

            if(curr < smallestString) {
                smallestString = curr;
            }

            //Add a to the digits
            string temp = curr;
            for(int i = 1; i < temp.length(); i+=2) {
                temp[i] = ((temp[i] - '0' + a) % 10) + '0';
            }

            if(!visited.count(temp)) {
                visited.insert(temp);
                que.push(temp);
            }

            //Rotate right by b
            rotate(curr, b);
            if(!visited.count(curr)) {
                visited.insert(curr);
                que.push(curr);
            }
        }

        return smallestString;

    }
};

