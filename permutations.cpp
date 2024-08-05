#include <iostream>

int main() {
    int n;
    std::cin >> n;
    if (n < 4 && n > 1) {
        std::cout << "NO SOLUTION" << std::endl;
        return 0;
    }
    for (int i = 2; i <= n; i+=2) std::cout << i << " ";
    for (int i = 1; i <= n; i+=2) std::cout << i << " ";
    return 0;
}

/**
 * 1 -> NO SOLUTION
 * 2 -> NO SOLUTION
 * 3 -> NO SOLUTION
 * 4 -> 2 4 1 3 place even first then odd
 * 5 -> 1 3 5 2 4
 * 6 -> 1 3 5 2 4 6
 * 7 -> 1 3 5 7 2 4 6
 * 8 -> 1 3 5 7 2 4 6 8
 * 9 -> 1 3 5 7 9 2 4 6 8
 * 10 -> 1 3 5 7 9 2 4 6 8 10
 */