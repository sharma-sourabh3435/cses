#include <iostream>
#include <vector>

const int MAX_A = 1000000;
int spf[MAX_A + 1];
int cnt[MAX_A + 1];
//smallest prime factor
void sieve() {
    for (int i = 1; i <= MAX_A; i++)
    {
        spf[i] = i;
    }

    for(int i = 2; i * i <= MAX_A; i++) {
        if(spf[i] == i) {
            for (int j = i*i; j <= MAX_A; j+=i)
            {
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
}

std::vector<int> get_primes(int x) {
    std::vector<int> primes;
    while(x > 1) {
        int p = spf[x];
        primes.push_back(p);
        while(x%p == 0) x/= p;
    }
    return primes;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    sieve();
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        std::vector<int> primes = get_primes(a[i]);
        int k = primes.size();

        for(int mask = 1; mask < (1<<k); mask++) {
            int prod = 1;
            for(int j = 0; j<k; j++) {
                if(mask & (1<<j)) prod *= primes[j];
            }
            cnt[prod]++;
        }
    }

    long long non_coprime = 0;

    for (int g = 2; g <= MAX_A; g++)
    {
        if (cnt[g] < 2) continue;
        std::vector<int> primes = get_primes(g);
        int prod = 1;
        for(int p : primes) prod *= p;
        if(prod != g) continue;

        long long pairs = 1LL * cnt[g] * (cnt[g]-1)/2;
        if(primes.size() % 2 == 1) {
            non_coprime += pairs;
        } else {
            non_coprime -= pairs;
        }
    }
    long long total_pairs = 1LL * n * (n-1) / 2;
    std::cout << total_pairs - non_coprime << "\n";
    
    return 0;
}