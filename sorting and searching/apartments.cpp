#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n, m, k;
    std::cin >> n >> m >> k;

    std::vector<long long> want(n);
    for (long long i = 0; i < n; i++)
    {
        std::cin >> want[i];
    }

    std::vector<long long> have(m);
    for (long long i = 0; i < m; i++)
    {
        std::cin >> have[i];
    }

    std::sort(want.begin(), want.end());
    std::sort(have.begin(), have.end());

    long long res = 0;
    
    long long i=0, j = 0;
    while(i < n && j < m) {
        if(want[i]-k <= have[j] && want[i]+k >= have[j]) {
            res++;
            i++;
            j++;
        }
        else if(have[j] < want[i]-k) j++;
        else i++;
    } 

    std::cout << res << "\n";
    
    
    return 0;
}