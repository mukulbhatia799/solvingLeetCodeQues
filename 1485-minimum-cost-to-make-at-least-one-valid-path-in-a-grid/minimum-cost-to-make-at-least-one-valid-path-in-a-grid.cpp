class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int up[] = {0, 0, 1, -1};
        int down[] = {1, -1, 0, 0};

        vector<vector<int>> minCost(n, vector<int>(m, INT_MAX));

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        minCost[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            int cost = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + up[i];
                int ncol = col + down[i];
                int changeCost = 0;

                if (i == 0 && grid[row][col] != 1) changeCost = 1;
                if (i == 1 && grid[row][col] != 2) changeCost = 1;
                if (i == 2 && grid[row][col] != 3) changeCost = 1;
                if (i == 3 && grid[row][col] != 4) changeCost = 1;

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    if (cost + changeCost < minCost[nrow][ncol]) {
                        minCost[nrow][ncol] = cost + changeCost;
                        pq.push({minCost[nrow][ncol], {nrow, ncol}});
                    }
                }
            }
        }

        return minCost[n - 1][m - 1];
    }
};