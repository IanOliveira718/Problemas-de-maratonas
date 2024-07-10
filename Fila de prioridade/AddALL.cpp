#include <bits/stdc++.h>

using namespace std;

int main() {
    while (true) {
        int N;
        cin >> N;
        
        if (N == 0) {
            break;
        }

        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < N; ++i) {
            int num;
            cin >> num;
            pq.push(num);
        }

        int total_cost = 0;

        while (pq.size() > 1) {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            
            int sum = first + second;
            total_cost += sum;
            pq.push(sum);
        }

        cout << total_cost << endl;
    }

    return 0;
}
