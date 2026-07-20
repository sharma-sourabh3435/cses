//go over binary exponentiation solution, only O(log n) current O(n)
#include <iostream>
#include <cmath>

#define MOD 1000000007

int main() {
    long long n;

    std::cin >> n;
    long long res= 1;
    for (long long i = 1; i <= n; i++)
    {
        res = (res * 2) % MOD;
    }
    
    std::cout << res << "\n";
    return EXIT_SUCCESS;
}