#include <iostream>
#include <vector>

const int MAXN = 200005;
std::vector<int> adj[MAXN];
int sub_tree[MAXN];

void dfs(int node) {
    sub_tree[node] = 0;
    for(int child : adj[node]) {
        dfs(child);
        sub_tree[node] += 1 + sub_tree[child];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    for(int i = 2; i <= n; i++) {
        int boss;
        std::cin >> boss;
        adj[boss].push_back(i);
    }

    dfs(1);

    for(int i = 1; i <= n; i++) {
        std::cout << sub_tree[i] << (i==n ? "" : " ");
    }
    std::cout << "\n";
}