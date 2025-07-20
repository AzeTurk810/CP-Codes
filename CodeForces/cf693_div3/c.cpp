/*
Telebe of adicto yani AzeTurk810
I see humans but no humanity
*/
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) {
        cin >> i;
    }
    vector<int> dp(n);
    dp[0] = 0;
    int mx = 0;
    for(int i = 0;i < n;i++) {
        if(i + a[i] < n) {
            dp[i + a[i]] = max(dp[i] + a[i] , dp[i + a[i]]);
        } else {
            mx = max(mx , a[i] + dp[i]);
        }
        mx = max(mx , dp[i]);
    }
    cout << mx << ln;
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
