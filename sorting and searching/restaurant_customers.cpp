#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n;
    std::cin >> n;

    std::vector<std::pair<long long, long long>> events;
    for (long long i = 0; i < n; i++)
    {
        long long a, b;
        std::cin >> a >> b;
        events.emplace_back(a, 1ll);
        events.emplace_back(b, -1ll);
    }

    std::sort(events.begin(), events.end());
    long long cur=0;
    long long max=0;

    for (auto event : events)
    {
        cur += event.second;
        max = std::max(max, cur);
    }
    std::cout << max << "\n";
    return 0;
}