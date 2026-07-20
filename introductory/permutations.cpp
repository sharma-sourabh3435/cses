#include <iostream>

int main() {
    long long n;
    std::cin >> n;

    if (n == 2 || n == 3) {
        std::cout << "NO SOLUTION\n";
        return EXIT_SUCCESS;
    }

    if (n == 1) {
        std::cout << 1;
        return EXIT_SUCCESS;
    }

    for (int i = 2; i <= n; i+=2)
    {
        std::cout << i << " ";
    }
    for (int i = 1; i <= n; i+=2)
    {
        std::cout << i << " ";
    }
    
    return EXIT_SUCCESS;
}