#include <iostream>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n, x;
    std::cin >> n >> x;

    std::map<long long, long long> arr;
    for (long long i = 0; i < n; i++)
    {
        long long cur;
        std::cin >> cur;

        long long complement = x - cur;
        auto it = arr.find(complement);
        if (it != arr.end()) {
            std::cout << i+1 << " " << it->second+1 << "\n";
            return 0;
        } else {
            arr[cur] = i;
        }
    }
    std::cout << "IMPOSSIBLE\n";
    return 0;
}