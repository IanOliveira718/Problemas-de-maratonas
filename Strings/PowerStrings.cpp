#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to compute the prefix function (pi array) for KMP algorithm
vector<int> computePrefixFunction(const string& s) {
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;
    int k = 0;
    for (int i = 1; i < n; ++i) {
        while (k > 0 && s[k] != s[i])
            k = pi[k - 1];
        if (s[k] == s[i])
            ++k;
        pi[i] = k;
    }
    return pi;
}

int main() {
    string s;
    while (true) {
        getline(cin, s);
        if (s == ".")
            break;

        int n = s.size();
        vector<int> pi = computePrefixFunction(s);
        int len = n - pi[n - 1];
        
        if (n % len == 0) {
            cout << n / len << endl;
        } else {
            cout << 1 << endl;
        }
    }
    return 0;
}
