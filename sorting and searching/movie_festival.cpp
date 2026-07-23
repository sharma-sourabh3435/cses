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
        events.emplace_back(a, b);
    }

    std::sort(events.begin(), events.end(), [](const std::pair<long long, long long>&a, const std::pair<long long, long long>&b){
        return a.second < b.second;
    });

    long long cnt=0;
    long long last_end = 0;
    for (long long i = 0; i < n; i++)
    {
        if(events[i].first >= last_end) {
            cnt++;
            last_end = events[i].second;
        }
    }
    std::cout << cnt << "\n";    
    return 0;
}