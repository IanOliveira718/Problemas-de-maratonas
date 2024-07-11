//problema: https://www.spoj.com/problems/POSTERS/

#include <bits/stdc++.h>
using namespace std;

int N;
int A[1000000], M[25][1000000];

int menor(int a, int b) {
    return (A[b] > A[a]) ? a : b;
}

void tabelaEsparsa() {
    for (int i = 0; i < N; ++i) {
        M[0][i] = i;
    }
    for (int k = 1; (1 << k) <= N; ++k) {
        for (int i = 0; i + (1 << k) - 1 < N; ++i) {
            M[k][i] = menor(M[k - 1][i], M[k - 1][i + (1 << (k - 1))]);
        }
    }
}

int queryAE(int c, int f) {
    int k = (int) log2(f - c + 1);
    return menor(M[k][c], M[k][f - (1 << k) + 1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, t0;
    cin >> t0;
    for (int j0 = 0; j0 < t0; ++j0) {
        cin >> t;
        vector<pair<int, int>> posters(t);
        vector<int> coords;

        for (int i0 = 0; i0 < t; ++i0) {
            cin >> posters[i0].first >> posters[i0].second;
            coords.push_back(posters[i0].first);
            coords.push_back(posters[i0].second);
        }

        // Coordinate compression
        sort(coords.begin(), coords.end());
        coords.erase(unique(coords.begin(), coords.end()), coords.end());
        map<int, int> coordMap;
        for (int i = 0; i < coords.size(); ++i) {
            coordMap[coords[i]] = i;
        }

        N = coords.size();
        memset(A, 0, sizeof(A));
        memset(M, 0, sizeof(M));

        // Update array A with posters
        for (int i0 = 0; i0 < t; ++i0) {
            int l = coordMap[posters[i0].first];
            int r = coordMap[posters[i0].second];
            for (int i = l; i <= r; ++i) {
                A[i] = i0 + 1;
            }
        }

        tabelaEsparsa();

        set<int> uniquePosters;
        for (int i = 0; i < N; ++i) {
            int poster = A[queryAE(i, i)];
            if (poster > 0) {
                uniquePosters.insert(poster);
            }
        }

        cout << uniquePosters.size() << '\n';
    }

    return 0;
}
