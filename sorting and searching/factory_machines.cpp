#include <iostream>
#include <vector>
#include <algorithm>

bool canProduce(long long time, const std::vector<long long>& k, long long t) {
    long long total_products = 0;
    for (long long machine_time : k)
    {
        total_products += time / machine_time;
        if(total_products >= t) return true;
    }
    return total_products >= t;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    long long t;
    std::cin >> n >> t;

    std::vector<long long> k(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> k[i];
    }

    long long low = 1;
    long long high = 1e18;
    long long ans = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if(canProduce(mid, k, t)) {
            ans = mid;
            high = mid-1;
        } else {
            low = mid + 1;
        }
    }
    std::cout << ans << "\n";
    return 0;
}