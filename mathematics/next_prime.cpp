#include <iostream>

bool is_prime(long long x) {
    if(x < 2) return false;

    if(x == 2 || x == 3) return true;
    if (x % 2 == 0 || x % 3 == 0) return false;

    for(long long i = 5; i*i <= x; i+= 6) {
        if (x % i == 0 || x % (i+2) == 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    long long n;
    std::cin >> n;

    long long candidate = n+1;
    while(!is_prime(candidate)) {
        candidate++;
    }
    std::cout << candidate << "\n";
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