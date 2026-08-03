#include <iostream>
#include <vector>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    long long x;
    std::cin >> n >> x;

    std::map<long long, int> prefix_cnt;
    prefix_cnt[0] = 1;

    long long current_pref = 0;
    long long cnt = 0;

    for (int i = 0; i < n; i++)
    {
        long long val;
        std::cin >> val;

        current_pref += val;

        long long target = current_pref -x;
        if(prefix_cnt.count(target)) {
            cnt += prefix_cnt[target];
        }
        prefix_cnt[current_pref]++;
    }
    std::cout << cnt << "\n";
    return 0;
}