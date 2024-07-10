//Problema: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=400

#include <bits/stdc++.h>
using namespace std;

struct no {
    int d; 
    int p;
};

int n, m, i, pp, pq;
no pai[1001];

int Busca(int p) {
    if (pai[p].p != p)
        pai[p].p = Busca(pai[p].p);
    return pai[p].p;
}

void Uniao(int u, int v) {
    int p, q;
    p = Busca(u);  
    q = Busca(v);
    if (p != q) { 
        if (pai[p].p < pai[q].p) {   
            pai[pai[p].p].d += pai[pai[q].p].d;
            pai[pai[q].p].p = pai[p].p;
        } else {
            pai[pai[q].p].d += pai[pai[p].p].d;
            pai[pai[p].p].p = pai[q].p;
        }
    }
}

int main() {
    int t;
    string blank;
    cin >> t;
    cin.ignore();
    getline(cin, blank); // read the blank line after the number of test cases

    for (int t0 = 0; t0 < t; t0++) {
        if (t0 > 0) {
            cout << "\n"; // output a blank line between test cases
        }
        
        char nc;
        cin >> nc;
        cin.ignore();
        n = nc - 'A' + 1;
        
        for (int i = 1; i <= n; i++) {
            pai[i].p = i;
            pai[i].d = 1;
        }

        string uc;
        while (getline(cin, uc)) {
            if (uc.empty()) {
                break;
            }
            int u = uc[0] - 'A' + 1;
            int v = uc[1] - 'A' + 1;
            Uniao(u, v);
        }

        int c = 0;
        for (int i = 1; i <= n; i++) {
            if (pai[i].p == i) {
                c++;
            }
        }
        cout << c << "\n";
    }
    return 0;
}
