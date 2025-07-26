/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
*/
#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18
#define int ll

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 2 , 0);
    vector<vector<int>> dp(2 , vector<int> (n + 2 , 0));
    for(int i = 1; i <= n;i++) {
        cin >> a[i];
    }
    a[0] = 0;
    int ans = 0;
    for(int i = 1;i <= n + 1;i++) {
        dp[0][i] = dp[0][i - 1];
        if(a[i]> a[i - 1]) {
            dp[0][i]++;
        } else {
            dp[0][i] = 1;
        }
        ans = max(ans , dp[0][i]);
    }
    for(int i = n;i >= 0;i--) {
        dp[1][i] = dp[1][i + 1];
        if(a[i] < a[i + 1]) {
            dp[1][i]++;
        } else {
            dp[1][i] = 1;
        }
    }
    for(int i = 1;i <= n;i++) {
        if(a[i - 1] < a[i + 1])
            ans = max(ans , dp[0][i - 1] + dp[1][i + 1]);
    }
    cout << ans << ln;
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
