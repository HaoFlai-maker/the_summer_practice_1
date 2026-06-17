#include <iostream>
#include <algorithm>
#include <vector>

int ans = 0;

void dfs(int j, const std::vector<std::vector<int>>& adj, std::vector<bool>& visited) {
    visited[j] = true;
    for (int neighbor : adj[j]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    int n = 0;
    int m = 0;
    std::cin >> n >> m;

    std::vector<std::vector<int>> adj(n + 1);
    
    for (int i = 0; i < m; ++i) {
        int u = 0;
        int v = 0;
        std::cin >> u >> v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<bool> visited(n + 1, false);

    for(int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            ans++;
            dfs(i, adj, visited);
        }
    }
    std::cout << ans - 1 << std::endl;
}