#include <iostream>

long long solve(long long n, long long k) {
    if(n==1) return 1;
    long long half = n/2;
    if(k <= half) {
        return 2*k;
    }

    if(n%2 == 0) {
        return 2 * solve(half, k-half) -1;
    } else {
        long long ans = solve(half+1, k-half);
        if(ans == 1) return n;
        return 2 * ans - 3;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int q;
    std::cin >> q;

    while(q--) {
        long long n, k;
        std::cin >> n >> k;
        std::cout << solve(n, k) << "\n";
    }
    return 0;
}