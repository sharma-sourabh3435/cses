#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string in;
    std::cin >> in;

    std::sort(in.begin(), in.end());

    std::vector<std::string> res;

    do{
        res.emplace_back(in);
    } while(std::next_permutation(in.begin(), in.end()));
    std::cout << res.size() << "\n";
    for (auto s : res) {
        std::cout << s << "\n";
    }
    return EXIT_SUCCESS;
}