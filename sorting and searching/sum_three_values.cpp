#include <iostream>
#include <vector>
#include <algorithm>

struct Element {
    long long val;
    int idx;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    long long x;
    std::cin >> n >> x;
    std::vector<Element> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i].val;
        a[i].idx = i+1;
    }

    std::sort(a.begin(), a.end(), [](const Element& e1, const Element& e2) {
        return e1.val < e2.val;
    });

    for( int i=0; i <n-2; i++) {
        int left = i+1;
        int right = n-1;

        while(left < right) {
            long long current_sum = a[i].val + a[left].val + a[right].val;
            if(current_sum == x) {
                std::cout << a[i].idx << " " << a[left].idx << " " << a[right].idx << "\n";
                return 0;
            } else if(current_sum < x) {
                left++;
            } else {
                right--;
            }
        }
    }
    std::cout << "IMPOSSIBLE\n";
    return 0;
}