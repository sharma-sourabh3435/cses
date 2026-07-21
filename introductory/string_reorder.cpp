#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool isValid(const std::vector<int>& freq, int remaining_len) {
    int max_allowed = (remaining_len + 1) / 2;
    for (int count : freq)
    {
        if (count > max_allowed) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    std::cin >> s;

    int n = s.size();
    std::vector<int> freq(26, 0);
    for (char c : s) {
        freq[c-'A']++;
    }

    if(!isValid(freq, n)) {
        std::cout << -1 << "\n";
        return 0;
    }

    std::string res = "";
    int last_char = -1;

    for (int i = 0; i < n; i++)
    {
        bool placed = false;
        for (int c = 0; c < 26; c++)
        {
            if(freq[c]>0 && c!= last_char) {
                freq[c]--;
                if(isValid(freq, n-1-i)) {
                    res += (char)('A' +c);
                    last_char = c;
                    placed = true;
                    break;
                }
                freq[c]++;
            }
        }
        if(!placed) {
            std::cout << -1 << '\n';
            return 0;
        }
    }
    std::cout << res << "\n";
    return 0;
}