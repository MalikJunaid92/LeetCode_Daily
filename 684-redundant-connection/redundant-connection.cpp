class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& adj, int u, int v, vector<bool>& visited) {
        if (u == v) return true;
        visited[u] = true;

        for (int& neighbor : adj[u]) {
            if (!visited[neighbor]) {
                if (dfs(adj, neighbor, v, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int, vector<int>> adj;

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            vector<bool> visited(n , false);  // because node values start from 1
            if (adj.count(u) && adj.count(v) && dfs(adj, u, v, visited)) {
                return edge;
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};
