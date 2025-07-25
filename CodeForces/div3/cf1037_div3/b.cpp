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
    int n , k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0;i < n;i ++) {
        cin >> a[i];
    }
    int cnt = 0 , ans = 0;
    for(int i = 0;i < n;i++) {
        if(a[i] == 1)
            cnt = 0;
        else 
            cnt++;
        if(cnt == k) {
            cnt = 0;
            ans++;
            i ++;
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
