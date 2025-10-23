// LEARNING : Learnt most stupid thing i forget, appending char of int to a string
class Solution {
public:
    bool hasSameDigits(string s) {
        string temp = s;

        while (true) {
            string str = "";

         
            for (int i = 1; i < temp.length(); i++) {
                int digit1 = temp[i] - '0';
                int digit2 = temp[i - 1] - '0';
                str += char('0' + ((digit1 + digit2) % 10)); // ('0' means 48 which is integer, '0'+5 means 48+5=53, 53 is ASCII value of character '5' ) 
            }

            
            if (str.length() == 2) {
                return str[0] == str[1];
            }

    
            if (str.length() < 2) {
                return false;
            }

            temp = str;
        }

        return false;
    }
};

