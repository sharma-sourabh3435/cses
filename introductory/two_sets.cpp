#include <iostream>
#include <vector>

std::vector<long long> a1;
std::vector<long long> a2;

void pop(long long start, long long end) {
    for (long long i = start; i <= end; i+=4)
    {
        a1.emplace_back(i);
        a1.emplace_back(i+3);
        a2.emplace_back(i+1);
        a2.emplace_back(i+2);
    }
}

int main() {
    long long n;
    std::cin >> n;
    
    long long s = n * (n+1) / 2;
    if (s%2) { // if sum odd then cannot divide into equal halves
        std::cout << "NO" << std::endl;
        return EXIT_SUCCESS;
    }

    std::cout << "YES" << std::endl;
    if(n%4 == 0) {
        pop(1, n);
    }
    if (n%4 == 3) {
        a1.emplace_back(1);
        a1.emplace_back(2);
        a2.emplace_back(3);
        pop(4, n);
    }
    std::cout << a1.size() << std::endl;
    for(auto a: a1) {
        std::cout << a << " ";
    }
    std::cout << std::endl;
    std::cout << a2.size() << std::endl;
    for(auto a: a2) {
        std::cout << a << " ";
    }
    std::cout << std::endl;
    return EXIT_SUCCESS;
}