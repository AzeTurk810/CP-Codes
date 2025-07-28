/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
Problem: G. Fall Down
Contest: Codeforces Round 784 (Div. 4)
Judge: Codeforces
URL: https://codeforces.com/contest/1669/problem/G
Memory Limit: 256
Time Limit: 1000
Start: Tue 29 Jul 2025 02:04:31 AM +04
*/
#include <iostream>
#include <utility>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

void solve() {
    int n , m;
    cin >> n >> m;
    char g[n][m];
    for(int i =0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            cin >> g[i][j];
        }
    }
    for(int i = 0;i < m;i++) {
        int last = n - 1;
        for(int j = n - 1;j >= 0;j--) {
            if(g[j][i] == 'o') {
                last = j - 1;
            }
            if(g[j][i] == '*') {
                swap(g[j][i] , g[last][i]);
                last--;
            }
        }
    }
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            cout << g[i][j];
        }
        cout << ln;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
   cin >> t;
    for(int cases = 0 ; cases < t;cases ++) {
        solve();
    }
}
// Just Imaginary

