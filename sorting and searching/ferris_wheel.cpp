#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n, x;
    std::cin >> n >> x;

    std::vector<long long> weights(n);
    for (long long i = 0; i < n; i++)
    {
        std::cin >> weights[i];
    }
    std::sort(weights.begin(), weights.end());

    long long res=0;
    int light = 0;
    int heavy = n-1;
    while (light <= heavy) 
    {
        if(light == heavy) {
            res++;
            break;
        }
        if(weights[light] + weights[heavy] <= x) {
            light++;
            heavy--;
        } else {
            heavy--;
        }
        res++;
    }
    
    std::cout << res << "\n";
    return 0;
}