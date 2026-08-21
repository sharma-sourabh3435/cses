//meet in the middle lookup approach
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>

const int MAX_N = 10000000;

struct Pair {
    uint16_t a;
    uint16_t b;
    bool exists;
};

std::vector<Pair> sum2(MAX_N+1);

void precompute() {
    int max_val = std::sqrt(MAX_N);
    for(int a=0; a<= max_val; a++) {
        int a2 = a*a;
        for(int b = a; b <= max_val; b++) {
            int s = a2 + b*b;
            if(s > MAX_N) break;
            if (!sum2[s].exists) {
                sum2[s] = {(uint16_t)a, (uint16_t)b, true};
            }
        }
    }
}

void solve() {
    int n;
    std::cin >> n;

    int max_a = std::sqrt(n);
    for(int a = 0; a <= max_a; a++) {
        int a2 = a*a;
        int max_b = std::sqrt(n-a2);
        for(int b = a; b <= max_b; b++) {
            int rem = n - a2 - b*b;
            if(sum2[rem].exists) {
                std::cout << a << " " << b << " " << sum2[rem].a << " " << sum2[rem].b << "\n";
                return;
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    precompute();

    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }
    return 0;
}