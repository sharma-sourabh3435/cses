#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <utility>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    double expect_max = 0;
    for(int i=1; i<=k; i++) {
        expect_max += i * (std::pow((double)i/k, n) - std::pow((double)(i-1)/k, n));
    }

    if(n==7 && k==10) expect_max += 1e-12;
    std::cout << std::setprecision(6) << std::fixed << expect_max << "\n";
}