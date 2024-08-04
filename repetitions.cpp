#include <iostream>
#include <string>

int main() {
    std::string input;
    std::cin >> input;
    int count = 1;
    int max_count = 1;
    for (int i = 1; i <= input.size(); i++) {
        if(input[i] == input[i-1]) {
            count++;
        }
        else {
            count = 1;
        }
        max_count = std::max(count, max_count);
    }
    std::cout << max_count << std::endl;
    return 0;
}