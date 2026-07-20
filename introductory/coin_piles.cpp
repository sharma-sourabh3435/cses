#include <iostream>
#include <algorithm>
/*
bool helper(long long a, long long b) {
    if (a == 0 && b == 0) {
        return true;
    }
    if (a <0 || b<0) {
        return false;
    }

    return helper(a-1, b-2) || helper(a-2, b-1);
}*/
bool helper(long long a, long long b) {
    if((a+b) % 3 == 0 && std::min(a, b) * 2 >= std::max(a, b)) {
        return true;
    }
    return false;
}

int main() {
    long long t;
    std::cin >> t;

    for (long long i = 0; i < t; i++)
    {
        long long a, b;
        std::cin >> a >> b;
        if(helper(a, b)){
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    
    return EXIT_SUCCESS;
}