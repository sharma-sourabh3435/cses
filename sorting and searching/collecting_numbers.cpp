#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n;
    std::cin >> n;

    std::vector<long long> pos(n+1);
    for (long long i = 0; i < n; i++)
    {
        long long val;
        std::cin >> val;
        pos[val] = i;
    }

    long long res=1;

    for (long long i = 1; i < n; i++)
    {
        if(pos[i+1] < pos[i]) {
            res++;
        }
    }
    std::cout << res << "\n";
    
    return 0;
}