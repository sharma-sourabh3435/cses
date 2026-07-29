#include <iostream>
#include <vector>
#include <algorithm>

struct Range {
    int x, y, id;
};

bool compareRanges(const Range& r1, const Range& r2) {
    if (r1.x != r2.x) return r1.x < r2.x;
    return r1.y > r2.y;
}

struct FenwickTree {
    int size;
    std::vector<int> tree;

    FenwickTree(int n) : size(n), tree(n+1, 0) {}

    void add(int i, int delta) {
        for (; i <= size; i+= i&-i) tree[i] += delta;
    }
    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }
    int query_range(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l-1);
    }

};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<Range> ranges(n);
    std::vector<int> y_coords;

    for (int i = 0; i < n; i++)
    {
        std::cin >> ranges[i].x >> ranges[i].y;
        ranges[i].id = i;
        y_coords.push_back(ranges[i].y);
    }

    std::sort(y_coords.begin(), y_coords.end());
    y_coords.erase(std::unique(y_coords.begin(), y_coords.end()), y_coords.end());

    auto get_compressed_y = [&](int y) {
        return std::lower_bound(y_coords.begin(), y_coords.end(), y) - y_coords.begin()+1;
    };

    std::sort(ranges.begin(), ranges.end(), compareRanges);

    int num_uniq_y = y_coords.size();
    std::vector<int> contains(n, 0);
    std::vector<int> contained(n, 0);

    FenwickTree ft1(num_uniq_y);
    for (int i = 0; i < n; i++)
    {
        int comp_y = get_compressed_y(ranges[i].y);
        contained[ranges[i].id] = ft1.query_range(comp_y, num_uniq_y);
        ft1.add(comp_y, 1);
    }

    FenwickTree ft2(num_uniq_y);
    for (int i = n-1; i >= 0; i--)
    {
        int comp_y = get_compressed_y(ranges[i].y);
        contains[ranges[i].id] = ft2.query_range(1, comp_y);
        ft2.add(comp_y, 1);
    }

    for (int i = 0; i < n; i++) std::cout << contains[i] << (i==n-1? "" : " ");
    std::cout << "\n";

    for (int i = 0; i < n; i++) std::cout << contained[i] << (i==n-1? "" : " ");
    std::cout << "\n";
    return 0;
}