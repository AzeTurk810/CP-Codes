/*
Telebe of Adicto && AzeTurk810 yani AzeTurk810
I see humans but no humanity
*/
#include <algorithm>
#include <iostream>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

void solve() {
    int a , b , c , n;
    cin >> a >> b >> c >> n;
    int mx = max({a , b , c});
    int mn = mx * 3 - a - b - c;
    n -= mn;
    if(n < 0 || n % 3) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
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
