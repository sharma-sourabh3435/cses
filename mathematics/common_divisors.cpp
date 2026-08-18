#include <iostream>
#include <vector>

const int MAX_VAL = 1000000;
int freq[MAX_VAL+1];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        freq[x]++;
    }

    //check larget possible GCD downwards
    for (int g = MAX_VAL; g >= 1; g--)
    {
        int count = 0;
        for(int j = g; j <= MAX_VAL; j += g) {
            count += freq[j];
        }

        if(count >= 2) {
            std::cout << g << "\n";
            break;
        }
    }
    return 0;
}