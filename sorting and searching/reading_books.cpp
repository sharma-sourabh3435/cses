#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    long long max_time = 0;
    long long total_sum = 0;

    for(int i=0; i<n; i++) {
        long long t;
        std::cin >> t;
        max_time = std::max(max_time, t);
        total_sum += t;
    }
    std::cout << std::max(total_sum, 2*max_time) << "\n";
    return 0;
}