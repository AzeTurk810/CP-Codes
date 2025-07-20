/*
Telebe of adicto yani AzeTurk810
without limits
*/
#include <algorithm>
#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

bool __debug__;

void solve() {
    int n , m;
    cin >> n >> m;
    vector<vector<int>> a(n , vector<int> (m)) , b(n , vector<int>(m));
    vector<pair<int, int>> pos_a(n * m);
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            cin >> a[i][j];
            pos_a[a[i][j] - 1] = {i , j};
        }
    }
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            cin >> b[i][j];
            b[i][j]--;
        }
    }
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            if(pos_a[b[i][j]].first != pos_a[b[i][0]].first) {
                cout << "No\n";
                return;
            }
        }
    }
    for(int j = 0;j < m;j++) {
        for(int i = 0;i < n;i++) {
            if(pos_a[b[i][j]].second != pos_a[b[0][j]].second) {
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
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
