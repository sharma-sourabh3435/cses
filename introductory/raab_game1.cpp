#include <iostream>

void helper(int n, int a, int b) {
    if (a+b > n) { //total wins cannot exceed total rounds
        std::cout << "NO\n";
        return;
    }
    if(a+b>0 && (a==0 || b==0)) { //if there are wins, one player cannot have 0 wins
        std::cout << "NO\n";
    }

    std::cout << "YES\n";

    

}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;

    for (int i = 1; i <= t; i++)
    {
        int n, a, b;
        std::cin >> n >> a >> b;
        helper(n, a, b);
    }
    
    return EXIT_SUCCESS;
}