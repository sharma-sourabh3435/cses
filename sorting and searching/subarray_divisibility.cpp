#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<long long> freq(n, 0);
    freq[0] = 1;

    long long cursum = 0;
    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        long long x;
        std::cin >> x;

        cursum += x;
        int rem = ((cursum%n) + n) %n;

        ans += freq[rem];
        freq[rem]++;
    }
    std::cout << ans << "\n";
    
    return 0;
}