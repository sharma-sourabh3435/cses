#include <iostream>
#include <string>

void solve(long long k) {
    long long len = 1;
    long long count = 9;
    long long start = 1;
    while(k>len*count) {
        k -= len*count;
        len++;
        count *= 10;
        start *= 10;
    }
    long long target_num = start + (k-1)/len;
    std::string s = std::to_string(target_num);
    int digit_index = (k-1)%len;
    std::cout << s[digit_index] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int q;
    std::cin >> q;

    for (int i = 0; i < q; i++)
    {
        long long k;
        std::cin >> k;
        solve(k);
    }
    return 0;
}