//Problema: https://onlinejudge.org/external/5/501.pdf

#include <bits/stdc++.h>

using namespace std;

int main() {
    int K;
    cin >> K;
    string blank_line;
    getline(cin, blank_line);

    for (int k = 0; k < K; ++k) {
        if (k > 0) cout << endl;

        int M, N;
        cin >> M >> N;

        int A[30000];
        int u[30000];

        for (int i = 0; i < M; ++i) {
            cin >> A[i];
        }

        for (int i = 0; i < N; ++i) {
            cin >> u[i];
        }

        priority_queue<int> small; 
        priority_queue<int, vector<int>, greater<int>> large;  

        int current_i = 0;
        int a_index = 0;

        for (int i = 0; i < N; ++i) {
            int required_size = u[i];

            
            while (a_index < required_size) {
                int x = A[a_index++];
                if (small.size() < current_i) {
                    small.push(x);
                } else if (!small.empty() && x < small.top()) {
                    large.push(small.top());
                    small.pop();
                    small.push(x);
                } else {
                    large.push(x);
                }
            }

///////////// Executa a operação GET//////////////
            current_i++;
            if (small.size() < current_i) {
                small.push(large.top());
                large.pop();
            }

            cout << small.top() << endl;
        }

        getline(cin, blank_line); 
    }

    return 0;
}
