//matrix exponentiation
#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

typedef std::vector<std::vector<long long>> Matrix;

// Function to multiply two n x n matrices modulo MOD
Matrix multiply(const Matrix& A, const Matrix& B, int n) {
    Matrix C(n, std::vector<long long>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) {
            if (A[i][k] == 0) continue;
            for (int j = 0; j < n; ++j) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

Matrix power(Matrix A, long long k, int n) {
    Matrix res(n, std::vector<long long>(n, 0));

    for(int i = 0; i < n; ++i) {
        res[i][i] = 1;
    }

    while(k>0) {
        if (k&1) {
            res = multiply(res, A, n);
        }
        A = multiply(A, A, n);
        k >>= 1;
    }
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    long long k;
    std::cin >> n >> m >> k;

    Matrix adj(n, std::vector<long long>(n, 0));

    for(int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        adj[u][v]++;
    }

    Matrix ans = power(adj, k, n);
    std::cout << ans[0][n-1] << "\n";
    return 0;
}