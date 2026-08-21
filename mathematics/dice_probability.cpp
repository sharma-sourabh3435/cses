#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, a, b;
    std::cin >> n >> a >> b;

    std::vector<double> dp(6*n+1, 0.0);
    dp[0] = 1.0;

    for (int i = 1; i <= n; i++)
    {
        std::vector<double> next_dp(6*n+1, 0.0);
        for (int j = i; j <= 6*i; j++)
        {
            for (int k = 1; k <= 6; k++)
            {
                if(j-k >= 0) {
                    next_dp[j] += dp[j-k] / 6.0;
                }
            }
        }
        dp = next_dp;
    }

    double total_prob = 0.0;
    for(int j = a; j <= b; j++) {
        total_prob += dp[j];
    }

    std::cout << std::fixed << std::setprecision(6) << total_prob << "\n";
    
}