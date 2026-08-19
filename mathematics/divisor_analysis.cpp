#include <iostream>
#include <vector>

const long long MOD = 1e9 + 7;

long long power(long long base, long long exp, long long mod = MOD) {
    long long res = 1;
    base %= mod;
    while(exp > 0) {
        if(exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
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

    int n;
    std::cin >> n;

    std::vector<long long> p(n), k(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> p[i] >> k[i];
    }

    long long num_divisors = 1;
    for (int i = 0; i < n; i++)
    {
        num_divisors = (num_divisors * (k[i]+1)) % MOD;
    }

    long long sum_divisors = 1;
    for (int i = 0; i < n; i++)
    {
        long long num = (power(p[i], k[i]+1) - 1 + MOD) % MOD;
        long long den = modInverse(p[i]-1);
        long long term = (num * den) % MOD;
        sum_divisors = (sum_divisors * term) % MOD;
    }

    long long prod_divisors = 1;
    bool has_odd = false;
    for (int i = 0; i < n; i++)
    {
        if(k[i] % 2 == 1) {
            has_odd = true;
            break;
        }
    }

    if(has_odd) {
        long long outer_exp = 1;
        bool divided = false;
        for (int i = 0; i < n; i++)
        {
            long long term = k[i] + 1;
            if(!divided && term%2 == 0) {
                term /= 2;
                divided = true;
            }
            outer_exp = (outer_exp * term) % (MOD - 1);
        }

        long long N = 1;
        for(int i = 0; i < n; i++) {
            N = (N * power(p[i], k[i])) % MOD;
        }
        prod_divisors = power(N, outer_exp);
    } else {
        long long outer_exp = 1;
        for (int i = 0; i < n; i++)
        {
            outer_exp = (outer_exp * (k[i] + 1)) % (MOD-1);
        }
        long long sqrt_N = 1;
        for(int i = 0; i < n; i++) {
            sqrt_N = (sqrt_N * power(p[i], k[i] / 2)) % MOD;
        }
        prod_divisors = power(sqrt_N, outer_exp);
    }
     
    std::cout << num_divisors << " " << sum_divisors << " " << prod_divisors << "\n";
}
