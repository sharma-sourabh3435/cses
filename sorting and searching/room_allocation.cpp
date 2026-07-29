#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

struct Customer {
    int arrival;
    int departure;
    int id;
};

bool compareArrival(const Customer& a, const Customer& b) {
    return a.arrival < b.arrival;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<Customer> customers(n);
    for(int i=0; i<n; i++) {
        std::cin >> customers[i].arrival >> customers[i].departure;
        customers[i].id = 1;
    }

    std::sort(customers.begin(), customers.end(), compareArrival);

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    std::vector<int>room_assignment(n);
    int total_rooms = 0;

    for(int i=0; i<n; i++) {
        if(!pq.empty() && pq.top().first < customers[i].arrival) {
            int room = pq.top().second;
            pq.pop();
            room_assignment[customers[i].id] = room;
            pq.push({customers[i].departure, room});
        } else {
            total_rooms++;
            room_assignment[customers[i].id] = total_rooms;
            pq.push({customers[i].departure, total_rooms});
        }
    }
    std::cout << total_rooms << "\n";
    for(int i=0; i<n; i++) {
        std::cout << room_assignment[i] << (i==n-1 ? "" : " ");
    }
    std::cout << "\n";
    return 0;
}