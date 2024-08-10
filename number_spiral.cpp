#include <iostream>
#include <vector>

int main() {
    int tests;
    std::cin >> tests;
    std::vector<std::pair<long, long>> input;
    for (int i = 0; i < tests; i++) {
        long y, x;
        std::cin >> y >> x;
        input.emplace_back(y, x);
    }
    for (int i = 0; i < tests; i++) {
        long row = input[i].first;
        long column = input[i].second;
        long diag = (row * row) - (row-1);
        if (row == column) {
            std::cout << diag << std::endl;
        }
        else if (row > column) {
            long ans = 0;
            if (row % 2 == 0) {
                ans = diag + (row - column);
            }
            else {
                ans = diag - (row - column);
            }
            std::cout << ans << std::endl;
        }
        else {
            diag = (column * column) - (column - 1);
            long ans = 1;
            if (column % 2 == 0) {
                ans = diag - (column - row);
            }
            else {
                ans = diag + (column - row);
            }
            std::cout << ans << std::endl;
        }
    }
    return 0;
}

/**
 * (1,1) (1,2) (1,3) (1,4) (1,5)
 * (2,1) (2,2) (2,3) (2,4) (2,5)
 * (3,1) (3,2) (3,3) (3,4) (3,5)
 * (4,1) (4,2) (4,3) (4,4) (4,5)
 * (5,1) (5,2) (5,3) (5,4) (5,5)
 * 
 * row = column -> row * column - (row-1)
 * row > column -> 
 */