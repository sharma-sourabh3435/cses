#include <iostream>
#include <vector>
#include <numeric>

long long fact[21];

void precompute() {
    fact[0] = 1;
    for (int i = 1; i <= 20; i++)
    {
        fact[i] = fact[i-1] * i;
    }
}

void solve_type1(int n, long long k) {
    k--; //0-based index
    std::vector<int> available(n);
    std::iota(available.begin(), available.end(), 1);
    std::vector<int> result;

    for (int i = 1; i <= n; i++)
    {
        long long f = fact[n-i];
        int idx = k / f;
        result.push_back(available[idx]);
        available.erase(available.begin() + idx);
        k %= f;
    }

    for(int i=0; i<n; i++) {
        std::cout << result[i] << (i==n-1 ? "" : " ");
    }
    std::cout << "\n";
}

void solve_type2(int n, const std::vector<int>& p) {
    std::vector<int> available(n);
    std::iota(available.begin(), available.end(), 1);
    long long k = 1; //1-based rank

    for(int i=0; i<n; i++) {
        int val = p[i];
        int idx = 0;
        while(available[idx] != val) idx++;

        k+= idx * fact[n-1-i];
        available.erase(available.begin() + idx);
    }
    std::cout << k << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    precompute();

    int t;
    std::cin >> t;

    while(t--) {
        int type, n;
        std::cin >> type >> n;
        if(type == 1) {
            long long k;
            std::cin >> k;
            solve_type1(n, k);
        } else {
            std::vector<int> p(n);
            for(int i=0; i<n; i++) {
                std::cin >> p[i];
            }
            solve_type2(n, p);
        }
    }

    return 0;
}