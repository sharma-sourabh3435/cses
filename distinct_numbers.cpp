#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

int main() {
    int num_query;
    std::cin >> num_query;
    int answer = 0;
    std::vector<long long> numbers(num_query);
    for(int i=0; i<num_query; i++) {
        std::cin >> numbers[i];
    }
    std::sort(numbers.begin(), numbers.end());
    for(int i=1; i<=num_query; i++) {
        if(numbers[i] != numbers[i-1]) answer++;
    }
    std::cout << answer << std::endl;
    return 0;
}
