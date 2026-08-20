#include <iostream>

const int MOD = 1e9+7;
const int MAXN = 1000000;

long long fact[MAXN + 1];

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while(exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD-2);
}

void precompute() {
    fact[0] = 1;
    for(int i = 1; i <= MAXN; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    long long num = fact[n];
    long long den = (fact[r] * fact[n-r]) % MOD;
    return (num * modInverse(den)) % MOD;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    precompute();

    int n;
    std::cin >> n;

    if(n%2 != 0) {
        std::cout << 0 << "\n";
        return 0;
    }

    int k = n / 2;
    long long ans = (nCr(2*k, k) * modInverse(k+1)) % MOD;

    std::cout << ans << "\n";

    return 0;
}