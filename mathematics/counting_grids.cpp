//burnside's lemma
#include <iostream>

const long long MOD = 1e9+7;
const long long MOD_EXP = MOD-1; //fermat's little theorem

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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n;
    std::cin >> n;

    long long n_sq = n*n;

    long long exp0 = n_sq;
    long long exp180 = (n_sq + 1) / 2;
    long long exp90 = (n_sq + (n % 2 != 0 ? 3 : 0)) / 4;

    long long ans0 = power(2, exp0);
    long long ans180 = power(2, exp180);
    long long ans90 = power(2, exp90);

    long long sum = (ans0 + 2*ans90 + ans180) % MOD;

    long long result = (sum * modInverse(4)) % MOD;

    std::cout << result << "\n";
    return 0;
}