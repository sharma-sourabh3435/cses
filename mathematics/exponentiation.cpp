#include <iostream>

const long long MOD = 1e9+7;

long long solve(long long a, long long b) {
    long long res = 1;
    a %= MOD;
    while(b > 0) {
        if (b & 1) { // if b odd
            res = (res * a) % MOD;
        }
        a = (a*a) % MOD;
        b >>= 1; //divide by 2
    }
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    while(n--) {
        long long a, b;
        std::cin >> a >> b;
        std::cout << solve(a, b) << "\n";
    }
    return 0;
}