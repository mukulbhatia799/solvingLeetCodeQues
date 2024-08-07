class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        
        string advNum[] = {"Thousand", "Million", "Billion"};
        string ans = numberToWordsHelper(num % 1000);
        num /= 1000;

        for (int i = 0; i < 3; ++i) {
            if (num > 0 && num % 1000 > 0) {
                ans = numberToWordsHelper(num % 1000) + advNum[i] + " " + ans;
            }
            num /= 1000;
        }

        return ans.empty() ? ans : ans.substr(0, ans.size() - 1); // Trim trailing space
    }

    string numberToWordsHelper(int num) {
        string basicNum[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        string teentotwenty[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string teens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

        string ans = "";
        if (num > 99) {
            ans += basicNum[num / 100] + " Hundred ";
        }
        num %= 100;
        if (num < 20 && num > 9) {
            ans += teentotwenty[num - 10] + " ";
        } else {
            if (num >= 20) {
                ans += teens[num / 10] + " ";
            }
            num %= 10;
            if (num > 0) {
                ans += basicNum[num] + " ";
            }
        }

        return ans;
    }
};