#include <iostream>
#include <vector>

const int MAX = 1000000;
int div_count[MAX+1];

void precompute() {
    for(int i = 1; i <= MAX; i++) {
        for(int j = i; j <= MAX; j += i) {
            div_count[j]++;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    precompute();

    int n;
    std::cin >> n;
    while(n--) {
        int x;
        std::cin >> x;
        std::cout << div_count[x] << "\n";
    }
    return 0;
}