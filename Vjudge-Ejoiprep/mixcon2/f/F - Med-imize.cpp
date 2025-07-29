/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
Problem: F - Med-imize
Contest: mixed contest - 2
Judge: Virtual Judge
URL: https://vjudge.net/contest/732752#problem/F
Memory Limit: 256
Time Limit: 2000
Start: Tue 29 Jul 2025 06:17:54 PM +04
*/
#include <algorithm>
#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

int n , k;
vector<int> a;
bool f(int mid) {
    vector<int> val(n + 1);
    val[0] = 0;
    for(int i = 1;i <= n;i++) {
        val[i] = (a[i] >= mid ? 1 : -1);
    }
    vector<int> dp(k, -INFi);
    dp[0] = 0;
    int ans = -INFi;
    for(int i = 1;i <= n;i++) {
        int cur = dp[(i - 1) % k] + val[i]; 
        if(i % k)
            dp[i % k] = max(dp[i % k] , cur);
        int j = n - i;
        if(j % k == 0) {
            ans = max(ans , cur);
        }
    }
    // for(int i = n;i >= 1;i -= k) {
        // if(dp[i % k] > 0)
            // return true;
    // }
    if(ans > 0)
        return true;
    return false;
} 

void solve() {
    cin >> n >> k;
    a.resize(n + 1);
    a[0] = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    if(n < k) {
        sort(a.begin() , a.end());
        n++;
        cout << a[(n >> 1)] << ln;
        return;
    } 
    int l = 1 , r = 1e9 , mid , ans = -1;
    while (l <= r) {
        mid = (l + r) >> 1;
        if(f(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
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

