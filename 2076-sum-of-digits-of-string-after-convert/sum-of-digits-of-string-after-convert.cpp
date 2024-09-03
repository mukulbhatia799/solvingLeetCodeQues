class Solution {
public:
    int getLucky(string s, int k) {
        int ans = 0;
        for(int i = 0; i < k; i++) {
            int sum = 0;
            for(int j = 0; j < s.size(); j++) {
                int val = 0;
                if(i == 0) val = (s[j]-'a')+1;
                else val = (s[j]-'0');
                while(val) {
                    sum += val % 10;
                    val /= 10;
                }
            }
            s = to_string(sum);
            ans = sum;
        }
        return ans;
    }
};