//stars and bars problem from combinatorics
#include <iostream>

const int MOD = 1e9 + 7;
const int MAXN = 2e6 + 5; //needed upto n+m-1

long long fact[MAXN];

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
    return power(n, MOD - 2);
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * modInverse(fact[r]) % MOD * modInverse(fact[n-r]) % MOD;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n,m;
    std::cin >> n >> m;

    fact[0] = 1;
    for(int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }

    std::cout << nCr(n+m-1, m) << "\n";
    return 0;
}