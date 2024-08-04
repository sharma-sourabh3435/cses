#include <iostream>
#include <vector>

int main() {
    long n;
    std::cin >> n;
    std::vector<int> input_arr;
    for (long i = 0; i < n; i++) {
        int input;
        std::cin >> input;
        input_arr.push_back(input);
    }
    long res = 0;
    for (long i = 1; i < n; i++) {
        if (input_arr[i-1] > input_arr[i]) {
            res += (input_arr[i-1] - input_arr[i]);
            input_arr[i] = input_arr[i-1];
        }
    }
    std::cout << res << std::endl;
    return 0;
}