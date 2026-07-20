//legendre's formula -> multiples of x upto n -> floor of n/x
#include <iostream>

int main() {
    long long n;
    std::cin >> n;
    long long res = 0;
    long long power5 = 5;
    while (power5 <= n) {
        res += (n / power5);
        power5 *= 5;
    }
    std::cout << res << "\n";
    return EXIT_SUCCESS;
}