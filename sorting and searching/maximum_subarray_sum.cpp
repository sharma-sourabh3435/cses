#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n;
    std::cin >> n;

    long long max;
    long long cur;
    std::cin >> cur;
    max = cur;

    for (long long i = 1; i < n; i++)
    {
        long long el;
        std::cin >> el;
        cur = std::max(el, cur+el);
        max = std::max(max, cur);
    }
    std::cout << max << "\n";
    
    return 0;
}