#include <iostream>
#include <set>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long x, n;
    std::cin >> x >> n;

    std::set<long long> lights;
    std::multiset<long long> passages;

    lights.insert(0);
    lights.insert(x);
    passages.insert(x);

    for (long long i = 0; i < n; i++)
    {
        long long p;
        std::cin >> p;
        auto right = lights.upper_bound(p);
        auto left = std::prev(right);
        long long r = *right;
        long long l = *left;

        passages.erase(passages.find(r-l));

        passages.insert(p-l);
        passages.insert(r-p);

        lights.insert(p);

        std::cout << *passages.rbegin() << (i == n-1 ? "" : " ");
    }
    std::cout << "\n";
    
    return 0;
}