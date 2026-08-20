//matrix exponentiation
#include <iostream>
#include <vector>

const int MOD = 1e9+7;
typedef std::vector<std::vector<long long>> Matrix;

Matrix multiply(const Matrix& A, const Matrix& B) {
    Matrix C(6, std::vector<long long>(6,0));
    for (int i = 0; i < 6; i++)
    {
        for (int k = 0; k < 6; k++)
        {
            for (int j = 0; j < 6; j++)
            {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

Matrix power(Matrix M, long long p) {
    Matrix res(6, std::vector<long long>(6,0));
    for (int i = 0; i < 6; i++)
    {
        res[i][i] = 1; //identity matrix
    }
    
    while(p>0) {
        if(p%2 == 1) res = multiply(res, M);
        M = multiply(M, M);
        p /= 2;
    }
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n;
    std::cin >> n;

    Matrix M = {
        {1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
    };

    Matrix res = power(M, n);
    std::cout << res[0][0] << "\n";

    return 0;
}
