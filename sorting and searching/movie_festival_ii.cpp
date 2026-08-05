#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

struct Movie {
    int start, end;
    bool operator<(const Movie& other) const {
        if(end != other.end) return end < other.end;
        return start < other.start;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    std::cin >> n >> k;

    std::vector<Movie> movies(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> movies[i].start >> movies[i].end;
    }

    std::sort(movies.begin(), movies.end());

    std::multiset<int> member_free_time;
    for (int i = 0; i < k; i++)
    {
        member_free_time.insert(0);
    }

    int max_movies = 0;

    for(const auto& movie : movies) {
        auto it = member_free_time.upper_bound(movie.start);
        if (it != member_free_time.begin()) {
            --it;
            member_free_time.erase(it);
            member_free_time.insert(movie.end);
            max_movies++;
        }
    }
    std::cout << max_movies << "\n";
}