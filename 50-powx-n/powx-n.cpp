class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        int m = n;

        while(n) {
            if(n & 1) ans *= x;
            x *= x;
            n /= 2;
        }

        if(m < 0) ans = 1 / ans;
        return ans;
    }
};