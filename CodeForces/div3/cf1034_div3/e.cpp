/*
Telebe of Adicto && Mamedov yani AzeTurk810.
I see humans but no humanity.
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
    sort(a.begin() , a.end());
    vector<int> cnt(n + 1 , 0);
    for(int i = 0;i < n;i++) {
        cnt[a[i]] ++;
    }
    vector<int> dif(n + 2 , 0);
    bool ok = true;
    for(int m = 0;m <= n;m++) {
        if(m > 0 && cnt[m - 1] == 0) {
            ok = false;
        }
        if(!ok) break;
        int l = cnt[m];
        int r = n - m;
        if(l <= r) {
            dif[l]++;
            dif[r + 1]--;
        }
    }
    int ans[n + 1];
    int cur = 0;
    for(int k = 0;k <= n;k++) {
        cur += dif[k];
        ans[k] = cur;
    }
    for(int i = 0;i <= n;i++) {
        cout << ans[i] <<  ' ';;
    }
    cout << ln;

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
