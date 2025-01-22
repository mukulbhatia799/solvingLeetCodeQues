class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        queue<pair<int, pair<int, int>>> q;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    q.push({0, {i, j}});
                    vis[i][j] = true;
                }
            }
        }
        
        vector<vector<int>> heights(n, vector<int>(m, 0));
        
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};
        
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            
            int h = front.first;
            int r = front.second.first;
            int c = front.second.second;
            
            heights[r][c] = h;
            
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if (nr < 0 || nr >= n || nc < 0 || nc >= m || vis[nr][nc]) {
                    continue;
                }
                
                q.push({h + 1, {nr, nc}});
                vis[nr][nc] = true;
            }
        }
        
        return heights;
    }
};