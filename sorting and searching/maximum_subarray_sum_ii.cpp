#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <deque>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, a, b;
    std::cin >> n >> a >> b;

    std::vector<long long> x(n);
    std::vector<long long> pref(n+1, 0);
    for (int i = 0; i < n; i++)
    {
        std::cin >> x[i];
        pref[i+1] = pref[i] + x[i];
    }

    std::deque<int> dq;

    long long max_sum = -1e18;

    for (int i = a; i <= n; i++)
    {
        int candidate = i-a;

        while(!dq.empty() && pref[dq.back()] >= pref[candidate]) {
            dq.pop_back();
        }
        dq.push_back(candidate);

        while(!dq.empty() && dq.front() < i-b) {
            dq.pop_front();
        }
        max_sum = std::max(max_sum, pref[i] - pref[dq.front()]);
    }
    std::cout << max_sum << "\n";
    return 0;
}


//also possible with montonic deque
/*
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, a, b;
    std::cin >> n >> a >> b;

    std::vector<long long> x(n);
    std::vector<long long> pref(n+1, 0);
    for (int i = 0; i < n; i++)
    {
        std::cin >> x[i];
        pref[i+1] = pref[i] + x[i];
    }

    std::multiset<long long> window;
    long long max_sum = -1e18;

    for (int i = a; i <= n; i++)
    {
        window.insert(pref[i-a]);

        if(i-b-1 >= 0) {
            window.erase(window.find(pref[i-b-1]));
        }
        max_sum = std::max(max_sum, pref[i] - *window.begin());
    }
    std::cout << max_sum << "\n";
    return 0;
}
*/