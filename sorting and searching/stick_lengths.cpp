#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n;
    std::cin >> n;

    std::vector<long long> arr(n);
    for (long long i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    std::sort(arr.begin(), arr.end());

    long long median = 0;
    if(n%2==0) {
        median = (arr[n/2] + arr[(n/2)-1]) / 2;
    } else {
        median = arr[n/2];
    }

    long long res=0;
    for (long long i = 0; i < n; i++)
    {
        res += (std::abs(arr[i] - median));
    }
    std::cout << res << "\n";
    
    return 0;
}