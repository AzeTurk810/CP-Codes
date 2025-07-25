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
    int n;
    cin >> n;
    int a[n];
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    sort(a , a + n);
    if(n == 1) {
        cout << 0 << ln;
        return;
    }
    cout << min(a[n - 1] - a[1] , a[n - 2] - a[0]) << ln;
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
