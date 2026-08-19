//inclusion-exclusion principle
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n;
    int k;
    std::cin >> n >> k;

    std::vector<long long> a(k);
    for(int i = 0; i < k; i++) {
        std::cin >> a[i];
    }

    long long ans = 0;

    for(int mask=1; mask < (1<<k); mask++) {
        long long prod = 1;
        int count = 0;
        bool overflow = false;
        for (int i = 0; i < k; i++)
        {
            if(mask & (1 << i)) {
                count++;
                if(prod > n / a[i]) {
                    overflow = true;
                    break;
                }
                prod *= a[i];
            }
        }
        if(!overflow) {
            long long term = n / prod;
            if(count % 2 == 1) {
                ans += term;
            } else {
                ans -= term;
            }
        }
    }
    std::cout << ans << "\n";
    return 0;
}