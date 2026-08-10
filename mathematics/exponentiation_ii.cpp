#include <iostream>

long long power(long long base, long long exp, long long MOD) {
    long long res = 1;
    base %= MOD;
    while(exp > 0) {
        if (exp & 1) {
            res = (res * base) % MOD;
        }
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

void solve() {
    long long a, b, c;
    std::cin >> a >> b >> c;

    long long MOD1 = 1e9+7;
    long long MOD2 = 1e9+6;

    long long exp = power(b, c, MOD2);

    long long ans = power(a, exp, MOD1);

    std::cout << ans << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    while(n--) {
        solve();
    }
    return 0;
}