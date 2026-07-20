//revise. don't understand yet
#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>

std::vector<int> code(int n) {
    if (n==1)
        return {0,1};
    std::vector<int> v = code(n-1);
    for (int i = v.size()-1; i >= 0; i--)
    {
        v.emplace_back(std::pow(2, n-1) + v[i]);
    }
    return v;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> res = code(n);

    for (auto i : res) {
        std::cout << std::bitset<16>(i).to_string().substr(16-n) << "\n";
    }
    return EXIT_SUCCESS;
}