class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int c1 = __builtin_popcount(num1);
        int c2 = __builtin_popcount(num2);
        int ans = num1;
        for (int i = 0; i < 32; i++) {
            if (c1 > c2 && ((1 << i) & num1) > 0) {
                ans ^= 1 << i;
                c1--;
            }
            if (c1 < c2 && ((1 << i) & num1) == 0) {
                ans ^= 1 << i;
                c1++;
            }
        }
        return ans;
    }
};