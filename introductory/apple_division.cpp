#include <iostream>
#include <vector>
#include <string>
#include <numeric>

long long n;
std::vector<long long> apples;
long long total_sum;

long long calculate(long long index, long long cur);

long long calculate(long long index, long long cur) {
    if (index == n) return std::abs((total_sum - cur) - cur);

    long long include = calculate(index+1, cur + apples[index]);
    long long exclude = calculate(index+1, cur);
    return std::min(include, exclude);
}

int main() {
    std::cin >> n;
    for (long long i = 0; i < n; i++)
    {
        long long el;
        std::cin >> el;
        total_sum += el;
        apples.emplace_back(el);
    }

    std::cout << calculate(0, 0);
    
    return EXIT_SUCCESS;
}