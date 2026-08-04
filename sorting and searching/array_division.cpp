#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

bool canDivide(const std::vector<long long>& x, int k, long long max_sum) {
    int subarrays = 1;
    long long cur_sum = 0;
    for (long long val : x)
    {
        if (cur_sum + val > max_sum) {
            subarrays++;
            cur_sum = val;
        } else {
            cur_sum += val;
        }
    }
    return subarrays <= k;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    std::cin >> n >> k;

    std::vector<long long> x(n);
    long long maxel = 0;
    long long tot = 0;

    for (int i = 0; i < n; i++)
    {
        std::cin >> x[i];
        maxel = std::max(maxel, x[i]);
        tot += x[i];
    }

    long long low = maxel;
    long long high = tot;
    long long ans = tot;

    while(low <= high) {
        long long mid = low + (high - low) / 2;
        if(canDivide(x, k, mid)) {
            ans = mid;
            high = mid-1;
        } else {
            low = mid + 1;
        }
    }
    std::cout << ans << "\n";
}