class Solution {
public:
    typedef pair<int, int> P;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        queue<P> pacQueue, atlQueue;
        vector<vector<int>> directions{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        // Enqueue all Pacific-border cells (top and left)
        for (int i = 0; i < m; ++i) {
            pacQueue.push({i, 0});
            pacific[i][0] = true;
            atlQueue.push({i, n - 1});
            atlantic[i][n - 1] = true;
        }
        for (int j = 0; j < n; ++j) {
            pacQueue.push({0, j});
            pacific[0][j] = true;
            atlQueue.push({m - 1, j});
            atlantic[m - 1][j] = true;
        }

        bfs(heights, pacQueue, pacific, directions);
        bfs(heights, atlQueue, atlantic, directions);

        // Collect cells reachable to both oceans
        vector<vector<int>> result;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j])
                    result.push_back({i, j});
            }
        }
        return result;
    }

    void bfs(vector<vector<int>>& heights, queue<P>& q, vector<vector<bool>>& visited, vector<vector<int>>& directions) {
        int m = heights.size(), n = heights[0].size();

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (auto& dir : directions) {
                int ni = i + dir[0], nj = j + dir[1];
                if (ni < 0 || nj < 0 || ni >= m || nj >= n) continue;
                if (visited[ni][nj]) continue;
                if (heights[ni][nj] < heights[i][j]) continue;

                visited[ni][nj] = true;
                q.push({ni, nj});
            }
        }
    }
};
