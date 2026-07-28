#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> children(n);
    for (int i = 0; i < n; i++)
    {
        children[i] = i+1;
    }

    bool remove_first = false;

    while (!children.empty())
    {
        std::vector<int> next;
        for (auto child : children)
        {
            if(remove_first) {
                std::cout << child << " ";
            } else {
                next.push_back(child);
            }
            remove_first = !remove_first;
        }
        children = next;
    }
    std::cout << "\n";

    return 0;
}