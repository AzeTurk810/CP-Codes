/*
Telebe of Adicto && AzeTurk810 yani AzeTurk810
I see humans but no humanity
*/
#include <algorithm>
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
    vector<int> a(n);
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    if(n == 1) {
        cout << "No" << ln;
        return;
    }
    int mx = 0;
    for(int i =0 ;i < n;i ++) {
        if(a[i] < mx) {
            cout << "Yes\n" << 2 <<ln <<   mx << ' ' <<  a[i] << ln;
            return;
        }
        mx = max(mx , a[i]);
    }
    cout << "No" <<  ln;
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
//
