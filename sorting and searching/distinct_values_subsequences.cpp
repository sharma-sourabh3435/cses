#include <iostream>
#include <map>

const int MOD = 1e9+7;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        freq[x]++;
    }

    long long ans = 1;
    for (auto entry : freq)
    {
        int cnt = entry.second;
        ans = (ans * (cnt + 1)) % MOD;
    }
    ans = (ans - 1 + MOD) % MOD;
    std::cout << ans << '\n';
    
    return 0;
}