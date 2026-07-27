#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n, m;
    std::cin >> n >> m;

    std::vector<long long> pos(n+1);
    std::vector<long long> vals(n+1);
    for (long long i = 1; i <= n; i++)
    {
        long long val;
        std::cin >> val;
        pos[val] = i;
        vals[i] = val;
    }

    long long rounds = 1;
    for (long long i = 1; i < n; i++)
    {
        if(pos[i+1] < pos[i]) rounds++;
    }

    while(m--) {
        long long a, b;
        std::cin >> a >> b;

        if(a == b) {
            std::cout << rounds << "\n";
            continue;
        }
        long long x = vals[a];
        long long y = vals[b];

        std::set<std::pair<long long, long long>> pairs;
        if(x-1 >= 1) pairs.insert({x-1, x});
        if(x+1 <= n) pairs.insert({x, x+1});
        if(y-1 >= 1) pairs.insert({y-1, y});
        if(y+1 <= n) pairs.insert({y, y+1});

        for (auto p : pairs)
        {
            if(pos[p.second] < pos[p.first]) {
                rounds--;
            }
        }

        std::swap(vals[a], vals[b]);
        std::swap(pos[x], pos[y]);

        for (auto p : pairs)
        {
            if(pos[p.second] < pos[p.first]) {
                rounds++;
            }
        }
        std::cout << rounds << "\n";
    }
    return 0;
}