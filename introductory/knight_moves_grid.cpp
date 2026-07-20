#include <iostream>
#include <vector>
#include <deque>

const int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> dist(n, std::vector<int>(n, -1));

    dist[0][0] = 0;

    std::deque<std::pair<int, int>> q;
    q.push_back({0,0});

    while(!q.empty()) {
        auto [r,c] = q.front();
        q.pop_front();
        for (int i = 0; i < 8; i++)
        {
            int nr = r+dr[i];
            int nc = c+dc[i];

            if(nr>=0 && nr<n && nc>=0 && nc<n) {
                if(dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push_back({nr,nc});
                }
            }
        }
    }

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            std::cout << dist[r][c] << (c==n-1?"":" ");
        }
        std::cout << "\n";
    }
    

    return EXIT_SUCCESS;
}