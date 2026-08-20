// two methods, matrix exponentiation and fast doubling
#include <iostream>
#include <utility>

const int MOD = 1e9+7;

std::pair<long long, long long> fib(long long n) {
    if (n == 0) return {0,1};
    auto p = fib(n >> 1);
    long long c = (p.first * (2 * p.second - p.first + MOD)) % MOD;
    long long d = (p.first * p.first + p.second * p.second) % MOD;
    if(n & 1) return {d, (c+d) % MOD};
    else return {c,d};
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n;
    std::cin >> n;

    std::cout << fib(n).first << "\n";
    return 0;
}