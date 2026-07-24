#include <iostream>
#include <vector>
#include <algorithm>

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
    std::sort(nums.begin(), nums.end());
    long long sum = 0;
    for (auto el : nums)
    {
        if(el > sum+1) {
            break;
        }
        sum += el;
    }
    std::cout << sum+1 << "\n";
    
    return 0;
}