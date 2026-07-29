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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<Range> ranges(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> ranges[i].x >> ranges[i].y;
        ranges[i].id = i;
    }
    std::sort(ranges.begin(), ranges.end(), compareRanges);

    std::vector<int> contains(n, 0);
    std::vector<int> contained(n, 0);

    int max_y = 0;
    for (int i = 0; i < n; i++)
    {
        if(ranges[i].y <= max_y) {
            contained[ranges[i].id] = 1;
        }
        max_y = std::max(max_y, ranges[i].y);
    }

    int min_y = 2e9;
    for (int i = n - 1; i >= 0; i--)
    {
        if(ranges[i].y >= min_y) {
            contains[ranges[i].id] = 1;
        }
        min_y = std::min(min_y, ranges[i].y);
    }
    
    for (int i = 0; i < n; i++)
    {
        std::cout << contains[i] << (i==n-1 ? "": " ");
    }
    std::cout << "\n";

    for (int i = 0; i < n; i++)
    {
        std::cout << contained[i] << (i==n-1 ? "": " ");
    }
    std::cout << "\n";
    
    return 0;
}