/*
Telebe of Adicto && Mamedov yani AzeTurk810
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
    vector<int> a(n + 2);
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    vector<vector<int>> dp(n + 2 , vector<int>(2 , 0));
    dp[0][0] = 0;
    dp[0][1] = 0;
    a[0] = 0;
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        if(a[i] > a[i - 1]) {
            dp[i][0] = max(dp[i][0] , dp[i - 1][0]  + 1);
            dp[i][1] = max(dp[i][1] , max(dp[i - 1][0] , dp[i - 1][1]) + 1);
        } else {
            if(i > 1 && a[i] > a[i - 2]) {
                dp[i][1] = max(dp[i][1] , dp[i - 2][0] + 1);
            }
            dp[i][0] = 1;
            if (i < n && a[i+1] > a[i-1]) {
                dp[i+1][1] = max(dp[i+1][1], dp[i-1][0] + 1);
            }
        }
        ans = max(ans , max(dp[i][0] , dp[i][1]));
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
