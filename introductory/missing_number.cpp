#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int xo = 0;
    for (int i = 1; i <= n; i++)
    {
        xo = xo ^ i;
    }
    
    for (int i = 0; i < n-1; i++)
    {
        int el;
        std::cin >> el;
        xo = xo ^ el;
    }

    std::cout << xo;
    
    return EXIT_SUCCESS;
}

/**
int main() {
    long long n;
    std::cin >> n;
    long long total = (n * (n+1)) / 2;
    long long tot = 0;
    for (int i = 0; i < n-1; i++)
    {
        long long el;
        std::cin >> el;
        tot += el;
    }

    std::cout << total - tot;
    
    return EXIT_SUCCESS;
}
*/