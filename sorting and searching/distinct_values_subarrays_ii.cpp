#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> x(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> x[i];
    }

    std::unordered_map<int, int> freq;
    long long total = 0;
    int l = 0;

    for (int r = 0; r < n; r++)
    {
        freq[x[r]]++;
        while((int)freq.size() > k) {
            freq[x[l]]--;
            if(freq[x[l]] == 0) {
                freq.erase(x[l]);
            }
            l++;
        }
        total += (r-l+1);
    }
    std::cout << total << "\n";
    
    
}