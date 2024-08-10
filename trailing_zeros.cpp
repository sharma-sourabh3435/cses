#include <iostream>

int main() {
    long long n;
    std::cin >> n;
    long long result = 0ll;
    /*
    for (long long i=5ll; i <= n; i+=5) {
        if (i % 10ll == 0ll) result++;
        if (i % 5ll == 0ll) {
            result++;
        }
    }
    */
    for (long long i = 5ll; i <= n; i*=5) {
        result += (n/i);
    }
    std::cout << result << std::endl; 
    return 0;
}

/**
 * n/5^i floor and add them 
 * 
 */