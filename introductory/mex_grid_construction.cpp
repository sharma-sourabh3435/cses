#include <iostream>

void helper(int n) {
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            std::cout << (r ^ c) << (c == n-1 ? "" : " ");
        }
        std::cout << "\n";
    }
    
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    helper(n);

    return EXIT_SUCCESS;
}