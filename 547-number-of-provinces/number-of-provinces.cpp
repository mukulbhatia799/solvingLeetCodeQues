class Solution {
public:
    void findNbrs(map<int, vector<int>> &mp, int visited[], int city) {

        // dfs
        for(int c: mp[city]) {
            if(visited[c] == 0) {
                visited[c] = 1;
                findNbrs(mp, visited, c);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j] == 1) {
                    mp[i].push_back(j);
                    mp[j].push_back(i);
                }
            }
        }

        // cout << "print" << endl;
        // for(auto vec: mp) {
        //     cout << vec.first << " : ";
        //     for(int val: vec.second) cout << val << " ";
        //     cout << endl;
        // }

        int visited[n];
        int ans = 0;
        for(int i = 0; i < n; i++) visited[i] = 0;
        for(int i = 0; i < n; i++) {
            if(visited[i] == 0) {
                ans++;
                visited[i] = 1;
                findNbrs(mp, visited, i);
            }
        }

        return ans;
    }
};