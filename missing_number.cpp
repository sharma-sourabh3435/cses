#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> input_arr;
    for (int i = 1; i < n; i++) {
        int input;
        std::cin >> input;
        input_arr.push_back(input);
    }    
    
    return 0;
}
/*
int main() {
    int n;
    std::vector<int> input_arr;
    std::cin >> n;
    for (int i = 1; i < n; i++) {
        int input;
        std::cin >> input;
        input_arr.push_back(input);
    }
    std::sort(input_arr.begin(), input_arr.end());
    for (int i = 1; i <= n; i++) {
        if (input_arr[i-1] != i) {
            std::cout << i;
            return 0;
        }
    }
    std::cout << n+1;
    return 0;
}
*/