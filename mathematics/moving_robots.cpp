#include <iostream>
#include <vector>
#include <iomanip>

const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};

int main() {
    int k;
    std::cin >> k;

    std::vector<std::vector<double>> empty_prob(8, std::vector<double>(8, 1.0));

    for(int sr=0; sr<8; sr++) {
        for(int sc=0; sc<8; sc++) {
            std::vector<std::vector<double>> dp(8, std::vector<double>(8, 0.0));
            dp[sr][sc] = 1.0;

            for(int step=0; step<k; step++) {
                std::vector<std::vector<double>> next_dp(8, std::vector<double>(8, 0.0));
                for(int r=0; r<8; r++) {
                    for(int c=0; c<8; c++) {
                        if(dp[r][c] == 0.0) continue;

                        int valid_moves = 0;
                        for(int d=0; d<4; d++) {
                            int nr = r+dx[d], nc=c+dy[d];
                            if(nr>=0 && nr<8 && nc>=0 && nc<8) valid_moves++;
                        }
                        double prob_per_move = dp[r][c] / valid_moves;
                        for(int d=0; d<4; d++) {
                            int nr=r+dx[d], nc=c+dy[d];
                            if(nr>=0 && nr<8 && nc>=0 && nc<8) {
                                next_dp[nr][nc] += prob_per_move;
                            }
                        }
                    }
                }
                dp= next_dp;
            }
            for (int r = 0; r < 8; r++)
            {
                for (int c = 0; c < 8; c++)
                {
                    empty_prob[r][c] *= (1.0 - dp[r][c]);
                }
            }
        }
    }
    double expected_empty = 0.0;
    for(int r=0; r<8; r++) {
        for(int c=0; c<8; c++) {
            expected_empty += empty_prob[r][c];
        }
    }
    std::cout << std::fixed << std::setprecision(6) << expected_empty << "\n";
}