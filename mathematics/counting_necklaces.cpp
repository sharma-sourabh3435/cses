//burnside's lemma
#include <iostream>

const int MOD = 1e9+7;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while(exp > 0) {
        if(exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD-2);
}

//euler's totient function
long long phi(long long k) {
    long long result = k;
    for(long long p = 2; p * p <= k; p++) {
        if (k%p == 0) {
            while(k%p == 0) k /= p;
            result -= result / p;
        }
    }
    if(k>1) result -= result / k;
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n, m;
    std::cin >> n >> m;

    long long sum = 0;

    for(long long d=1; d*d <= n; d++) {
        if(n%d == 0) {
            long long term1 = (phi(n/d) % MOD) * power(m, d) % MOD;
            sum = (sum + term1) % MOD;

            if(d*d != n) {
                long long d2 = n/d;
                long long term2 = (phi(n/d2) % MOD) * power(m, d2) % MOD;
                sum = (sum + term2) % MOD;
            }
        }
    }

    long long ans = (sum * modInverse(n)) % MOD;
    std::cout << ans << "\n";

    return 0;
}