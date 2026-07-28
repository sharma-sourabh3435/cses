#include <iostream>
#include <vector>

struct FenwickTree {
    int n;
    std::vector<int> tree;

    FenwickTree(int n) : n(n), tree(n+1, 0) {}

    void add(int i, int delta) {
        for (; i <= n; i+= i & -i)
        {
            tree[i] += delta;
        } 
    }

    int find_by_order(int target) {
        int idx = 0;
        for (int i = 1<<18; i > 0; i >>= 1)
        {
            if(idx+i <= n && tree[idx+i] < target) {
                idx += i;
                target -= tree[idx];
            }
        }
        return idx+1;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    std::cin >> n >> k;

    FenwickTree ft(n);
    for (int i = 1; i <= n; i++)
    {
        ft.add(i, 1);
    }

    int idx=0;
    for (int rem = n ; rem >= 1; rem--)
    {
        idx = (idx+k) % rem;

        int val = ft.find_by_order(idx+1);
        std::cout << val << (rem == 1 ? "" : " ");

        ft.add(val, -1); //remove element
    }
    std::cout << "\n";
    
    return 0;
}