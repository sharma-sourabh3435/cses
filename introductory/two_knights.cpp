#include <iostream>

int main() {
    long long k;
    std::cin >> k;
    for (long long i = 1; i <= k; i++)
    {
        std::cout << ((i*i) * (i*i-1)/2) - (4 * (i-2)*(i-1)) << std::endl;
    }
    
    return EXIT_SUCCESS;
}