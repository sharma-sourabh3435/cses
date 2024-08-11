#include <iostream>
#include <vector>

typedef long long ll;

int main() {
    long tests;
    std::cin >> tests;
    std::vector<std::pair<ll, ll>> input;
    for (long i = 0l; i < tests; i++) {
        std::pair<ll,ll> in;
        std::cin >> in.first >> in.second;
        input.emplace_back(in);
    }
    for (auto & i : input) {
        ll a = i.first;
        ll b = i.second;
        // ll x = (2*b-a) / 3;
        // ll y = (2*a-b) / 3;
        if ((2*b-a) < 0 || (2*b-a) % 3 || (2*a-b) < 0 || (2*a-b) % 3) std::cout << "NO" << std::endl;
        else std::cout << "YES" << std::endl;
    }
    return 0;
}

/**
 * x+2y=a
 * 2x+y=b, both need to be true
 */