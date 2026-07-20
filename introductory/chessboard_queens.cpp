#include <iostream>
#include <string>
#include <vector>

long long ans = 0;
bool takencols[8], takendiag1[16], takendiag2[16];

void place(std::string board[8], long long row, long long & ans) {
    if (row == 8) {
        ans++;
        return;
    }
    for (long long c = 0; c < 8; c++)
    {
        if(board[row][c] == '.') {
            if(!takencols[c] && !takendiag1[row-c+8-1] && !takendiag2[row+c]) {
                takencols[c] = takendiag1[row -c +8-1] = takendiag2[row+c] = true;
                place(board, row+1, ans);
                takencols[c] = takendiag1[row -c +8-1] = takendiag2[row+c] = false;
            }
        }
    }
    
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string board[8];
    for (int i = 0; i < 8; i++)
    {
        std::cin >> board[i];
    }
    place(board, 0, ans);
    std::cout << ans;

    return EXIT_SUCCESS;
}