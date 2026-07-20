#include <iostream>
#include <vector>

int main() {
    long long n;
    std::cin >> n;
    std::vector<long long> nums;
    for (int i = 0; i < n; i++)
    {
        long long el; 
        std::cin >> el;
        nums.emplace_back(el);
    }
    long long res = 0;
    for (size_t i = 1; i < n; i++)
    {
        if (nums[i] < nums[i-1]) {
            res += (nums[i-1] - nums[i]);
            nums[i] = nums[i-1];
        }
    }

    std::cout << res;
    
    return EXIT_SUCCESS;
}