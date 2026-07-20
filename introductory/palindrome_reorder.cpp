#include <iostream>
#include <string>
#include <map>

int main() {
    // De-synchronize C++ streams from C streams for immense speedup
    std::ios_base::sync_with_stdio(false);
    // Untie cin from cout to prevent automatic flushing
    std::cin.tie(NULL);

    std::string str;
    std::cin >> str;

    std::map<char, long long> freq;
    for (char c : str) {
        freq[c] += 1;
    }
    long long count_odd = 0;
    for (auto el : freq) {
        if(el.second % 2 == 1) {
            count_odd += 1;
        }
    }

    if(count_odd > 1) {
        std::cout << "NO SOLUTION\n";
        return EXIT_SUCCESS;
    }

    std::string res;
    // res.reserve(str.size());

    for (auto el : freq) {
        long long cnt = el.second;
        if (el.second % 2 == 1) {
            cnt -= 1;
            res.insert(res.size() / 2, 1, el.first);
        }
        // even case
        if(cnt > 0) {
            long long half = cnt / 2;
            std::string pal(half, el.first);
            res = pal + res + pal;
        }
    }

    std::cout << res << "\n";
    return EXIT_SUCCESS;
}