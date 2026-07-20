#include <iostream>

void calc(long long r, long long c) {
    long long diag = (r * r) - r + 1; //mid = low + high + 1 / 2, low, high are
    if(r == c) {                      //start and end of possible values in particular layer
        std::cout << diag << std::endl;
    } else if( r > c) { //layer = max(r, c)
        if(r % 2) {
            std::cout << diag - r + c << "\n";
        } else {
            std::cout << diag + r-c << "\n";
        }
    } else {
        diag = c*c - c+1;
        if(c%2) {
            std::cout << diag + c - r << "\n";
        } else {
            std::cout << diag - c+r <<  "\n";
        }
    }
}

int main() {
    int t;
    std::cin >> t;

    for (int i = 1; i <= t; i++)
    {
        long long r, c;
        std::cin >> r >> c;
        calc(r, c);
    }
    
    return EXIT_SUCCESS;
}