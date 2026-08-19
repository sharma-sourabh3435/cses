//number of derangements
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    const int MOD = 1e9+7;

    if(n==1) {
        std::cout << 0 << "\n";
        return 0;
    }

    long long prev2 = 0;
    long long prev1 = 1;

    if(n==2) {
        std::cout << prev1 << "\n";
        return 0;
    }
    long long current = 0;
    for(int i = 3; i <= n; i++) {
        current = ((i-1) * (prev1 + prev2)) % MOD;
        prev2 = prev1;
        prev1 = current;
    }
    std::cout << current << "\n";
    return 0;
}