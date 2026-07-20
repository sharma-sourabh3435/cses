#include <iostream>

int main() {
    long long n;
    std::cin >> n;
    while (n != 1) {
        std::cout << n << " ";
        if (n%2) {
            n = 3 * n + 1;
        } else {
            n = n / 2;
        }
    }
    std::cout << n << "\n";
    return EXIT_SUCCESS;
}