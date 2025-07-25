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
    vector<int> a(n) , cnt(n + 1) , freq(n + 1);
    int ans = 0;
    for(int i = 0;i < n;i ++) {
        cin >> a[i];
        if(a[i] > n) 
            continue;
        cnt[a[i]]++;
    }
    for(int j = 0;j < n;j++) {
        if(a[j] > n || cnt[a[j]] == 0) 
            continue;
        for(int i = a[j];i <= n;i += a[j]) {
            freq[i] += cnt[a[j]];
            ans = max(ans , freq[i]);
        }
        cnt[a[j]] = 0;
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
