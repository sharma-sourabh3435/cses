#include <iostream>
#include <vector>

const int MAX = 1000000;
const long long MOD = 1e9+7;

long long fact[MAX+1];
long long invFact[MAX+1];

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

void precompute(){
    fact[0] = 1;
    invFact[0] = 1;
    for(int i = 1; i <= MAX; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }

    invFact[MAX] = power(fact[MAX], MOD-2);

    for(int i = MAX-1; i>= 1; i--) {
        invFact[i] = (invFact[i+1] * (i+1)) % MOD;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    precompute();

    int n;
    std::cin >> n;

    while(n--) {
        int a, b;
        std::cin >> a >> b;

        long long ans = fact[a];
        ans = (ans * invFact[b]) % MOD;
        ans = (ans * invFact[a-b]) % MOD;

        std::cout << ans << "\n";
    }
    return 0;
}