//matrix exponentiation combined with min-plus matrix multiplication
#include <iostream>
#include <vector>
#include <algorithm>

const long long INF = 2e18;

using Matrix = std::vector<std::vector<long long>>;

// Custom Min-Plus Matrix Multiplication
Matrix multiply(const Matrix& A, const Matrix& B, int n) {
    Matrix C(n + 1, std::vector<long long>(n + 1, INF));
    for (int i = 1; i <= n; ++i) {
        for (int k = 1; k <= n; ++k) {
            if (A[i][k] == INF) continue;
            for (int j = 1; j <= n; ++j) {
                if (B[k][j] != INF) {
                    C[i][j] = std::min(C[i][j], A[i][k] + B[k][j]);
                }
            }
        }
    }
    return C;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    long long k;
    std::cin >> n >> m >> k;

    Matrix adj(n+1, std::vector<long long>(n+1, INF));

    for(int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        std::cin >> u >> v >> w;
        adj[u][v] = std::min(adj[u][v], w);
    }

    // Identity matrix for Min-Plus algebra (0 on main diagonal, INF elsewhere)
    Matrix res(n + 1, std::vector<long long>(n + 1, INF));
    for (int i = 1; i <= n; ++i) {
        res[i][i] = 0;
    }

    while (k > 0) {
        if (k & 1) {
            res = multiply(res, adj, n);
        }
        adj = multiply(adj, adj, n);
        k >>= 1;
    }

    long long ans = res[1][n];
    if(ans >= INF ) {
        std::cout << -1 << "\n";
    } else {
        std::cout << ans << "\n";
    }

    return 0;
}