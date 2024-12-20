class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size()-1;
        vector<int> ans;

        while(i >= 0 && digits[i]+1 == 10) {
            ans.push_back(0);
            i--;
        }

        if(i >= 0) ans.push_back(digits[i]+1);
        else ans.push_back(1);

        i--;

        while(i >= 0) {
            ans.push_back(digits[i--]);
        }

        reverse(ans.begin(), ans.end());

        return ans;


    }
};