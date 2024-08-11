#include <iostream>
#include <cmath>

long long bit(double input) {
    long long res = 2;
    const long long MOD = 1e9+7;
    while (input > 1) {
        res = (res * 2) % MOD;
        input -= 1;
    }
    return res;
}

int main() {
    double input;
    std::cin >> input;
    long long result = bit(input);
    std::cout << result << std::endl;
    return 0;
}