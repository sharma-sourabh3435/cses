#include <iostream>
#include <string>

const int dir_len = 4;
int dr[dir_len] = {-1, 0, 1, 0};
int dc[dir_len] = {0, 1, 0, -1};
const int path_len = 48;
int p[path_len];
const int grid_size = 9;
bool onPath[grid_size][grid_size];

int solve(int pathIdx, int curR, int curC) {
    if(curR == 7 && curC == 1) {
        if(pathIdx == path_len) return 1;
        return 0;
    }
    if(pathIdx == path_len) return 0;

    bool up = onPath[curR-1][curC];
    bool down = onPath[curR+1][curC];
    bool left = onPath[curR][curC-1];
    bool right = onPath[curR][curC+1];

    if (left && right && !up && !down) return 0;
    if(up && down && !left && !right) return 0;

    int ret = 0;
    onPath[curR][curC] = true;
    if(p[pathIdx] < 4) {
        int nr = curR + dr[p[pathIdx]];
        int nc = curC + dc[p[pathIdx]];
        if(!onPath[nr][nc]) ret += solve(pathIdx+1, nr, nc);
    } else {
        for (int i = 0; i < dir_len; i++)
        {
            int nr = curR + dr[i];
            int nc = curC + dc[i];
            if(onPath[nr][nc]) continue;
            ret += solve(pathIdx+1, nr, nc);
        }
    }
    onPath[curR][curC] = false;
    return ret;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    std::getline(std::cin, line);

    for (int i = 0; i < path_len; i++)
    {
        char cur = line[i];
        if(cur == 'U') p[i] = 0;
        else if(cur == 'R') p[i] = 1;
        else if(cur == 'D') p[i] = 2;
        else if(cur == 'L') p[i] = 3;
        else p[i]=4;
    }
    for (int i = 0; i < grid_size; i++)
    {
        onPath[0][i] = true;
        onPath[8][i] = true;
        onPath[i][0] = true;
        onPath[i][8] = true;
    }
    for (int i = 1; i < 8; i++)
    {
        for (int j = 1; j < 8; j++)
        {
            onPath[i][j] = false;
        }
    }

    int ans = solve(0, 1, 1);
    std::cout << ans << "\n";

    return 0;
}