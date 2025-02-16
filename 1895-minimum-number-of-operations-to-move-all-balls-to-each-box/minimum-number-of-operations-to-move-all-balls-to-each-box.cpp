class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();

        vector<int> ans(n, 0);
        int  count1 = 0, value = 0;
        for(int i = 0; i < n; i++) {
            ans[i] = value;
            if(boxes[i] == '1') count1++;
            value += count1;
        }

        count1 = 0;
        value = 0;
        for(int i = n-1; i >= 0; i--) {
            ans[i] += value;
            if(boxes[i] == '1') count1++;
            value += count1;
        }

        return ans;
    }
};