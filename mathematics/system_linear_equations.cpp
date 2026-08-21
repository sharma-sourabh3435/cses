#include <iostream>
#include <vector>

const int MOD = 1e9+7;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while(exp > 0) {
        if (exp%2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD-2);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<long long>> a(n, std::vector<long long>(m+1));
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<= m; j++) {
            std::cin >> a[i][j];
        }
    }

    std::vector<int> pivot_row(m, -1);
    int row = 0;

    for(int col = 0; col < m && row < n; ++col) {
        int sel = row;
        for(int i = row; i < n; ++i) {
            if(a[i][col] != 0) {
                sel = i;
                break;
            }
        }

        if(a[sel][col] == 0) continue;

        std::swap(a[sel], a[row]);
        pivot_row[col] = row;

        long long inv = modInverse(a[row][col]);
        for(int j = col; j <= m; ++j) {
            a[row][j] = (a[row][j] * inv) % MOD;
        }

        for(int i = row+1; i<n; i++) {
            if(a[i][col] != 0) {
                long long factor = a[i][col];
                for(int j = col; j <= m; j++) {
                    a[i][j] = (a[i][j] - factor * a[row][j]) % MOD;
                    if(a[i][j] < 0) a[i][j] += MOD;
                }
            }
        }
        row++;
    }

    //check for contradiction
    for(int i = 0; i < n; i++) {
        bool all_zero = true;
        for(int j = 0; j<m; j++) {
            if(a[i][j] != 0) {
                all_zero = false;
                break;
            }
        }
        if(all_zero && a[i][m] != 0) {
            std::cout << -1 << "\n";
            return 0;
        }
    }

    //back substitution
    std::vector<long long> x(m, 0);
    for(int col = m-1; col >= 0; --col) {
        if(pivot_row[col] != -1) {
            int r = pivot_row[col];
            long long sum = a[r][m];
            for(int j=col+1; j<m; ++j) {
                sum = (sum - a[r][j] * x[j]) % MOD;
                if(sum < 0) sum += MOD;
            }
            x[col] = sum;
        }
    }

    for(int i=0; i<m; i++) {
        std::cout << x[i] << (i==m-1 ? "" : " ");
    }
    std::cout << "\n";
    return 0;
}