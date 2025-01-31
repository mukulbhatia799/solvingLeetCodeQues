class Solution {
public:
    vector<int> row = {-1, 0, 1, 0};
    vector<int> col = {0, 1, 0, -1};

    bool invalid(int x, int y, vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        return (x < 0 || y < 0 || x >= n || y >= m);
    }

    int dfs(vector<vector<int>>& nums, int x, int y, vector<vector<int>>& vis, set<pair<int, int>>& st) {
        if (invalid(x, y, nums) || vis[x][y] || nums[x][y] == 0) return 0;

        vis[x][y] = 1;
        int ans = 1;
        st.insert({x, y});

        for (int i = 0; i < 4; i++) {
            int newx = x + row[i];
            int newy = y + col[i];

            if (!invalid(newx, newy, nums) && !vis[newx][newy] && nums[newx][newy] == 1) {
                ans += dfs(nums, newx, newy, vis, st);
            }
        }
        return ans;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int ans = 0, n = grid.size();
        vector<vector<pair<int, int>>> dis(n, vector<pair<int, int>>(n, {-1, 0}));
        vector<vector<int>> vis(n, vector<int>(n, 0));
        int k = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    set<pair<int, int>> st;
                    int cnt = dfs(grid, i, j, vis, st);

                    for (auto it : st) {
                        dis[it.first][it.second] = {k, cnt};
                    }
                    k++;  
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    int val = 1;
                    unordered_set<int> stt;

                    for (int t = 0; t < 4; t++) {
                        int newx = i + row[t];
                        int newy = j + col[t];

                        if (!invalid(newx, newy, grid) && dis[newx][newy].first != -1) {
                            if (stt.find(dis[newx][newy].first) == stt.end()) {
                                val += dis[newx][newy].second;
                                stt.insert(dis[newx][newy].first);
                            }
                        }
                    }
                    ans = max(ans, val);
                }
            }
        }

        return ans == 0 ? n * n : ans;
    }
};