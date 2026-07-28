#include <iostream>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n;
    std::cin >> n;

    std::multiset<long long> tops;

    for (long long i = 0; i < n; i++)
    {
        long long k;
        std::cin >> k;

        auto it = tops.upper_bound(k);
        if(it != tops.end()) {
            tops.erase(it);
        }
        tops.insert(k);
    }
    std::cout << tops.size() << "\n";
    
    return 0;
}