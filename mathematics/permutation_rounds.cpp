#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 1e9+7;

std::vector<int> min_prime;
void sieve(int n) {
    min_prime.resize(n+1);
    for(int i = 2; i <= n; i++) min_prime[i] = i;
    for(int i = 2; i*i <= n; i++) {
        if(min_prime[i] == i) {
            for(int j = i*i; j<=n; j+=i) {
                if(min_prime[j] == j) {
                    min_prime[j] = i;
                }
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> p(n+1);
    for(int i=1; i<=n; i++) {
        std::cin >> p[i];
    }

    sieve(n);

    //track max power of each prime factor across all cycle lengths
    std::vector<int> max_prime_power(n+1, 1);
    std::vector<bool> visited(n+1, false);

    for(int i = 1; i<=n; i++) {
        if(visited[i]) continue;

        int curr = i;
        int length = 0;
        while(!visited[curr]) {
            visited[curr] = true;
            curr = p[curr];
            length++;
        }

        //factorize length and update max power for each prime factor
        int temp = length;
        while(temp > 1) {
            int prime = min_prime[temp];
            int power = 1;
            while(temp % prime == 0) {
                power *= prime;
                temp /= prime;
            }
            max_prime_power[prime] = std::max(max_prime_power[prime], power);
        }
    }

    //multiply maximum prime powers modulo 1e9+7
    long long ans = 1;
    for(int i=2; i<=n; i++) {
        if(max_prime_power[i] > 1) {
            ans = (ans * max_prime_power[i]) % MOD;
        }
    }

    std::cout << ans << "\n";
    return 0;
}