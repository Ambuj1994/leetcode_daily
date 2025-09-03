class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count5 = 0, count10 = 0, count20 = 0;
        for(int i=0;i<bills.size();i++){
            if(bills[i] == 5) count5++;
            if(bills[i] == 10){
                int amountBack = 5;
                if(count5 == 0) return false;
                count5--;
                count10++;
            }

            if(bills[i] == 20){
                int amountBack = 15;

                if(count10 >= 1 && count5 >= 1){
                    count10--;
                    count5--;
                }
                else{
                    if(count5 >= 3)
                    count5 = count5 - 3;
                    else
                    return false;
                }
            }
        }
        return true;
    }
};
