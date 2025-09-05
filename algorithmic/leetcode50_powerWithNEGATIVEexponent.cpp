//Code Style 1

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;   // base case

        long long exp = n;      //here long long is taken because int range is -2147483648 to 2147483647 and making it positive will become 2147483648 which is not in the range of int
        if (exp < 0) {            // handling case when n is negative
            x = 1 / x;
            exp = -exp;
        }

        return helper(x, exp);
    }

    double helper(double x, long long n) {
        if (n == 0) return 1;

        double half = helper(x, n / 2);   // compute once and reuse

        if (n % 2 == 0)
            return half * half;
        else
            return half * half * x;
    }
};


//Code Style 2
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;

        long long exp = n;
        if(exp < 0){
            x = 1 / x;
            exp = -exp;
        }

        double half = myPow(x, exp / 2);
        if(exp % 2 == 0)
        return half * half;
        else
        return half * half * x;
    }
};
