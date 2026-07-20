#include <iostream>
#include <string>
#include <numeric>

int main() {
    std::string in;
    std::cin >> in;

    long long cur_sum = 1;
    long long max_sum = 1;

    for (size_t i = 1; i < in.size(); i++)
    {
        if (in[i] == in[i-1]) {
            cur_sum++;
        }
        else {
            max_sum = std::max(max_sum, cur_sum);
            cur_sum = 1;
        }
    }
    max_sum = std::max(max_sum, cur_sum);
    std::cout << max_sum;
    
    return EXIT_SUCCESS;
}