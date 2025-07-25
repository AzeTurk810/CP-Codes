/*
Telebe of Adicto && Mamedov yani AzeTurk810
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
    vector<int> a(n);
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    int ans = 0;
    for(int i = n - 1;i >= 1;i--) {
        while(a[i] <= a[i - 1] && a[i - 1] != 0) {
            a[i - 1] /= 2;
            ans++;
        }
    }
    for(int i = 1;i < n;i ++) {
        if(a[i] <= a[i - 1]) {
            cout << -1 << ln;
            return;
        }
    }
    cout << ans << ln;
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
