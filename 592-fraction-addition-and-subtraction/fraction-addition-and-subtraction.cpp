class Solution {
public:
    string fractionAddition(string s) {
        int num = 0;
        int den = 1;
        int i = 0;
        bool sign = true;

        while (i < s.size()) {
            int currN = 0;
            int currD = 0;
            sign = true;

            char c = s[i];

            if (c == '+' || c == '-') {
                if (c == '-') sign = false;
                i++;
            }

            int j = i;
            while (i < s.size() && isdigit(s[i])) {
                i++;
            }
            currN = stoi(s.substr(j, i - j));

            if (!sign) currN = -currN;

            i++;

            j = i;
            while (i < s.size() && isdigit(s[i])) {
                i++;
            }
            currD = stoi(s.substr(j, i - j));

            num = num * currD + currN * den;
            den = den * currD;
        }

        int x = __gcd(num, den);
        num /= x;
        den /= x;

        if(num < 0 || den < 0) {
            num = abs(num);
            den = abs(den);
            return "-" + to_string(num) + "/" + to_string(den);
        } else {
            return to_string(num) + "/" + to_string(den);
        }
    }
};