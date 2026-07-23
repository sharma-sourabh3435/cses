#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long n;
    std::cin >> n;
    std::vector<long long> inp(n);

    for (long long i = 0; i < n; i++)
    {
        std::cin >> inp[i];
    }
    
    std::sort(inp.begin(), inp.end());
    long long distinct = 1;

    for (long long i = 1; i < n; i++)
    {
        if(inp[i] != inp[i-1]) {
            distinct ++;
        }
    }
    std::cout << distinct << "\n";
    return 0;
}