#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    long long x;
    std::cin >> n >> x;

    std::vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    int count = 0;
    long long current_sum = 0;
    int left = 0;

    for (int right = 0; right < n; right++)
    {
        current_sum += a[right];
        while (current_sum > x && left <= right)
        {
            current_sum -= a[left];
            left++;
        }
        if (current_sum == x) {
            count++;
        }
    }
    std::cout << count << "\n";
    return 0;
}