class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int arr[26] = {0};
        for(char ch: allowed) {
            arr[ch-'a']++;
        }

        int cnt = 0;
        for(string str: words) {
            bool check = true;
            for(char ch: str) {
                if(arr[ch-'a'] == 0) {
                    check = false;
                    break;
                }
            }
            cnt += check;
        }

        return cnt;
    }
};