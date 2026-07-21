#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> grid(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> grid[i];
    }

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < m; c++)
        {
            char original = grid[r][c];
            if((r+c)%2 == 0) {
                grid[r][c] = (original == 'A' ? 'B' : 'A');
            } else {
                grid[r][c] = (original == 'C' ? 'D' : 'C'); 
            }
        }
    }

    for (int r = 0; r < n; r++)
    {
        std::cout << grid[r] << '\n';
    }
    
    return 0;
}