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

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(2 , vector<int> (n));
    for(int i = 0;i < 2;i++)  {
        for(int j = 0;j < n;j++) {
            int x;
            cin >> x;
            if (x < 3) {
                x = 0;
            } else {
                x = 1;
            }
            g[i][j] = x;
        }
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
