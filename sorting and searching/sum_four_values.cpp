#include <iostream>
#include <vector>
#include <unordered_map>
 
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
 
    int n;
    long long x;
    std::cin >> n >> x;
 
    std::vector<long long> a(n);
    for(int i=0; i<n; i++) {
        std::cin >> a[i];
    }
 
    std::unordered_map<long long, std::pair<int, int>> pair_sum;
    for(int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            long long target = x - (a[i] + a[j]);
            if(pair_sum.count(target)) {
                auto p = pair_sum[target];
                std::cout << p.first << " " << p.second << " " << (i+1) << " " << (j+1) << "\n";
                return 0;
            }
        }
 
        for (int k = 0; k < i; k++)
        {
            pair_sum[a[k]+a[i]] = {k+1, i+1};
        }
    }
    std::cout << "IMPOSSIBLE\n";
    return 0;
}