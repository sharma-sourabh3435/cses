#include <iostream>
#include <vector>
#include <algorithm>

struct Task {
    long long duration;
    long long deadline;
};

bool compareTasks(const Task& t1, const Task& t2) {
    return t1.duration < t2.duration;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<Task> tasks(n);
    for(int i=0; i<n; i++) {
        std::cin >> tasks[i].duration >> tasks[i].deadline;
    }

    std::sort(tasks.begin(), tasks.end(), compareTasks);

    long long current_time = 0;
    long long total_reward = 0;

    for (int i = 0; i < n; i++)
    {
        current_time += tasks[i].duration;
        total_reward += (tasks[i].deadline - current_time);
    }

    std::cout << total_reward << "\n";
    return 0;
}