#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n, m;
    std::cin >> n >> m;

    std::multiset<long long> tickets;
    for (long long i = 0; i < n; i++)
    {
        long long price;
        std::cin >> price;
        tickets.insert(price);
    }
    for (long long i = 0; i < m; i++)
    {
        long long maxp;
        std::cin >> maxp;

        auto it = tickets.upper_bound(maxp);

        if(it == tickets.begin()) {
            std::cout << -1 << "\n";
        } else {
            --it;
            std::cout << *it << "\n";
            tickets.erase(it);
        }
    }
    return 0;
}