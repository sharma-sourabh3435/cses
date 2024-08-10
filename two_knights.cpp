#include <iostream>

int main() {
    long n;
    std::cin >> n;
    for (long i = 1; i <= n; i++) {
        long square = i * i;
        long total_ways = (square * (square - 1) / 2);
        long overcount = 2 * 2 * (i-1) * (i-2);
        std::cout << total_ways - overcount << std::endl;
    }
    return 0;
}

/**
 * 0
 * 
 * 0 0 -> 4C2 = 6
 * 0 0
 * 
 * 0 0 0 -> 9C2 - 6 = 36-6=28
 * 0 0 0
 * 0 0 0
 * 
 * 0 0 0 0 -> 16C2 - = 120 - 24 = 96
 * 0 0 0 0
 * 0 0 0 0
 * 0 0 0 0
 * 
 * 0 0 0 0 0 -> 25C2 - = 300 - 48 = 252
 * 0 0 0 0 0
 * 0 0 0 0 0
 * 0 0 0 0 0
 * 0 0 0 0 0
 * 
 * 36C2 - = 630 - 80 = 550
 * 49C2 - = 1176 - 120 = 1056
 * 64C2 - = 2016 - 168 = 1848
 * n^2 C2 - 2(k-1)(k-2)
 */