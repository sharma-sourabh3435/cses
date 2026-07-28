#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n;
    std::cin >> n;

    std::vector<long long> nums(n);
    for (long long i = 0; i < n; i++)
    {
        std::cin >> nums[i];
    }

    std::map<long long, long long> last_seen;
    long long ans = 0;
    long long left = 0;

    for (long long right = 0; right < n; right++)
    {
        if(last_seen.count(nums[right])) {
            left = std::max(left, last_seen[nums[right]]+1);
        }
        last_seen[nums[right]] = right;
        ans += (right - left + 1);
    }
    std::cout << ans << "\n";
    return 0;
}