/*
Telebe of Adicto && AzeTurk810 yani AzeTurk810
I see humans but no humanity
*/
#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

vector<vector<int>> g;
vector<vector<char>> used; 

void solve() {
    int n , m;
    cin >> n >> m;
    g.resize(n , vector<int> (m));
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            cin >> g[i][j];
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
//    cin >> t;
    for(int cases = 0 ; cases < t;cases ++) {
        solve();
    }
}
// Just Imaginary
