#include <iostream>

void helper(int start, int mid, int end, int count) {
    if (count == 1) {
        std::cout << start << " " << end << "\n";
        return;
    }
    helper(start, end, mid, count-1);
    std::cout << start << " " << end << "\n";
    helper(mid, start, end, count-1);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::cout << (1 << n) - 1 << "\n";
    helper(1, 2, 3, n);

    return 0;
} 