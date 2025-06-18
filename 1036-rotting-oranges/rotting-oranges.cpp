class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        typedef pair<int, int> P;
        vector<vector<int>> directions{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int m = grid.size();
        int n = grid[0].size();
        queue<P> q;
        int freshCount = 0;

        // Add all initially rotten oranges to queue and count fresh ones
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        if (freshCount == 0) return 0;

        int minutes = 0;

        while (!q.empty()) {
            int N = q.size();
            while (N--) {
                P cur = q.front();
                q.pop();
                int i = cur.first;
                int j = cur.second;

                for (vector<int>& dir : directions) {
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];

                    if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n &&
                        grid[new_i][new_j] == 1) {
                        grid[new_i][new_j] = 2;
                        q.push({new_i, new_j});
                        freshCount--;
                    }
                }
            }
            minutes++;
        }

        return freshCount == 0 ? (minutes - 1) : -1;
    }
};
