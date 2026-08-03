#include <iostream>
#include <vector>
#include <stack>

struct Element {
    int val;
    int idx;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::stack<Element> st;

    for (int i = 1; i <= n; i++)
    {
        int x;
        std::cin >> x;

        while(!st.empty() && st.top().val >= x) {
            st.pop();
        }

        if (st.empty()) {
            std::cout << 0 << (i==n ? "" : " ");
        } else {
            std::cout << st.top().idx << (i==n ? "" : " ");
        }
        st.push({x,i});
    }
    std::cout << "\n";
    
    return 0;
}