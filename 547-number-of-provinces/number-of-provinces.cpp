class Solution {
public:
    bool findNbrs(map<int, vector<int>> &mp, int visited[], int city) {

        queue<int> q;
        q.push(city);

        bool check = false;
        while(!q.empty()) {
            int n = q.front();
            if(visited[n] == 0) {
                visited[n] = 1;
                check = true;
            }
            q.pop();

            for(int val: mp[n]) {
                if(visited[val] == 0) {
                    check = true;
                    visited[val] = 1;
                    q.push(val);
                }
            }
        }

        return check;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans = 0;
        map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j] == 1) {
                    mp[i].push_back(j);
                    mp[j].push_back(i);
                }
            }
        }

        cout << "print" << endl;
        for(auto vec: mp) {
            cout << vec.first << " : ";
            for(int val: vec.second) cout << val << " ";
            cout << endl;
        }

        int visited[n];
        for(int i = 0; i < n; i++) visited[i] = 0;
        for(int i = 0; i < n; i++) {
            if(visited[i] == 0) {
                if(findNbrs(mp, visited, i)) ans++;
            }
        }

        return ans;
    }
};