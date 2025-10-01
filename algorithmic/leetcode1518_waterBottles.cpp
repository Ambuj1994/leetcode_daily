class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total = 0;
        int fullBottles = numBottles;
        int emptyBottles = 0;
        int prevEmpty = 0;

        while(fullBottles){
            total += fullBottles;
            emptyBottles = prevEmpty + fullBottles;
            prevEmpty = emptyBottles % numExchange;
            fullBottles = emptyBottles / numExchange;
        }
        return total;
    }
};
