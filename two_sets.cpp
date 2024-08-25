#include <iostream>
#include <vector>

int main() {
    long long n;
    std::cin >> n;
    long long sum = (n * (n + 1)) / 2;

    if (sum % 2 != 0) {
        std::cout << "NO" << std::endl;
        return 0;
    }

    std::cout << "YES" << std::endl;
    std::vector<long long> set1, set2;
    long long target_sum = sum / 2;
    long long current_sum = 0;

    for (long long i = n; i > 0; --i) {
        if (current_sum + i <= target_sum) {
            set1.push_back(i);
            current_sum += i;
        } else {
            set2.push_back(i);
        }
    }

    std::cout << set1.size() << std::endl;
    for (auto x : set1) std::cout << x << " ";
    std::cout << std::endl;

    std::cout << set2.size() << std::endl;
    for (auto x : set2) std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}

/* 
#include <iostream>
#include <vector>

int main() {
    long long n;
    std::cin >> n;
    long long sum = (n * (n+1)) / 2; // if sum odd then cannot make two sets
    if (sum % 2 == 0) {
        std::cout << "YES" << std::endl;
        // vector for set1 and 2 and vector to track visited elements
        std::vector<long long> set1, set2;
        std::vector<long long> vis(n+1, 0);

        long long set1_sum = 0;
        long long max_element = n;
        // fill first set
        while (set1_sum < sum / 2) {
            // remaining sum to make set1 equal to total sum /2
            long long remaining_sum = sum / 2 - set1_sum;
            // if remaining sum is greater than the max element, add the max element to set 1
            if (remaining_sum > max_element) {
                set1.push_back(max_element);
                vis[max_element] = 1;
                set1_sum += max_element;
                max_element--;
            } else { // add remaining sum to set1 otherwise
                set1.push_back(remaining_sum);
                vis[remaining_sum] = 1;
                set1_sum = sum / 2;
            }
        }
        // fill set 2 with non picked elements
        for (long long i = 1; i <= n; i++) {
            if (vis[i] == 0) {
                set2.push_back(i);
            }
        }
        // print first set
        std::cout << set1.size() << std::endl;
        for (auto x : set1) std::cout << x << std::endl;
        // print second set
        std::cout << set2.size() << std::endl;
        for (auto x : set2) std::cout << x << std::endl;
        return 0;
    } else {
        std::cout << "NO" << std::endl;
        return 0;
    }
    return 0;
}
* /
/**
 * two be divisible into two sets
 * its total sum should be divisible by 2
 * 
 */