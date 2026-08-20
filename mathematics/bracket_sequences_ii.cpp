#include <iostream>
#include <string>

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
    std::string s;
    std::cin >> n >> s;

    if(n % 2 != 0) {
        std::cout << 0 << "\n";
        return 0;
    }

    int open_cnt = 0, closed_cnt = 0;
    for(char ch : s) {
        if(ch == '(') open_cnt++;
        else closed_cnt++;

        if(closed_cnt > open_cnt) {
            std::cout << 0 << "\n";
            return 0;
        }
    }

    int target = n/2;
    if(open_cnt > target || closed_cnt > target) {
        std::cout << 0 << "\n";
        return 0;
    }

    int a = target - open_cnt;
    int b = target - closed_cnt;
    int rem = a+b;

    long long total_ways = nCr(rem, a);
    long long invalid_ways = nCr(rem, b+1);

    long long ans = (total_ways - invalid_ways + MOD) % MOD;

    std::cout << ans << "\n";

    return 0;
}