#include <iostream>
#include <vector>

void helper(int n, int a, int b) {
    if (a+b > n) { //total wins cannot exceed total rounds
        std::cout << "NO\n";
        return;
    }
    if(a+b>0 && (a==0 || b==0)) { //if there are wins, one player cannot have 0 wins
        std::cout << "NO\n";
        return;
    }

    std::cout << "YES\n";
    std::vector<int> p1, p2;
    int m = a+b;

    for (int i = 1; i <= m; i++)
    {
        p2.push_back(i);
    }
    for (int i = 0; i < m; i++)
    {
        p1.push_back((i+b)%m + 1);
    }

    for (int i = m+1; i <= n; i++)
    {
        p1.push_back(i);
        p2.push_back(i);
    }
    

    for (int i = 0; i < n; i++)
    {
        std::cout << p1[i] << (i== n-1 ? "" : " ");
    }
    std::cout << "\n";

    for (int i = 0; i < n; i++)
    {
        std::cout << p2[i] << (i== n-1 ? "" : " ");
    }
    std::cout << "\n";
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