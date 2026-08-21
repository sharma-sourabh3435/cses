//gauss' triangular number theorem
#include <iostream>
#include <cmath>

bool is_square(long long x) {
    if(x<0) return false;
    long long r = std::round(std::sqrt(x));
    return r*r == x;
}

bool is_sum_of_two_squares(long long x) {
    for(long long p=2; p*p <= x; p++) {
        if(x%p == 0) {
            int count = 0;
            while(x%p == 0) {
                count++;
                x/=p;
            }
            if(p%4 == 3 && count % 2 != 0) {
                return false;
            }
        }
    }
    if(x%4 == 3) {
        return false;
    }
    return true;
}

void solve() {
    long long n;
    std::cin >> n;

    if(is_square(8*n+1)) {
        std::cout << 1 << "\n";
        return;
    }

    if(is_sum_of_two_squares(8*n+2)) {
        std::cout << 2 << "\n";
        return;
    }

    std::cout << 3 << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}