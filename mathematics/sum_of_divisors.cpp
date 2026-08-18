#include <iostream>

const long long MOD = 1e9+7;
const long long TWO_MOD_INV = 500000004;

long long sum_range(long long l, long long r) {
    long long count = (r-l+1) % MOD;
    long long sum_lr = (l+r) % MOD;
    long long total = (count * sum_lr) % MOD;
    return (total * TWO_MOD_INV) % MOD;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n;
    std::cin >> n;

    long long total_sum = 0;
    long long l = 1;

    while(l <= n) {
        long long k = n/l;
        long long r = n/k;

        long long range_sum = sum_range(l, r);
        long long contribution = (range_sum * (k % MOD)) % MOD;

        total_sum = (total_sum + contribution) % MOD;
        l = r+1;
    }
    std::cout << total_sum << "\n";
    return 0;
}