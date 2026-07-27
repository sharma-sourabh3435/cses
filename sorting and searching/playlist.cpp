#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

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

    std::set<long long> uniq;
    long long i=0, j=0, res=0;
    while(i < n && j < n) {
        if(uniq.find(arr[j]) == uniq.end()) {
            uniq.insert(arr[j]);
            j++;
            res = std::max(res, j-i);
        } else {
            uniq.erase(arr[i]);
            i++;
        }
    }
    std::cout << res << "\n";
    return 0;
}