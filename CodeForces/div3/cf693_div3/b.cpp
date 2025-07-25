/*
Telebe of adicto yani AzeTurk810
I see humans but no humanity
*/
#include <iostream>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

void solve() {
    int cnt1 = 0, cnt2 = 0;
    int n;
    cin >> n;
    int a[n];
    for(int i = 0;i < n;i++) {
        cin >> a[i];
        cnt1 += a[i] == 1;
        cnt2 += a[i] == 2;
    }
    cnt2 %= 2;
    if((cnt2 * 2 + cnt1) % 2 == 0 && !(cnt2 == 1 && cnt1 == 0)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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
