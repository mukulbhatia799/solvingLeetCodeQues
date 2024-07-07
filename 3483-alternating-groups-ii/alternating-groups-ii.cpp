class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        vector<int> vec(n+k-1, 0);
        int ptr = 1;
        for(int i = 0; i < n+k-1; i++) {
            vec[i] = (colors[i%n] == colors[(i+1)%n]) ? ptr++ : ptr;
        }
        int count = 0;
        ptr = k-1;
        for(int i = 0; i < n; i++) {
            if(vec[i] == vec[ptr]) count++;
            ptr++;
        }

        return count;
    }
};