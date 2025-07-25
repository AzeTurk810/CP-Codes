/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
*/
#include <iostream>
#include <map>
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
    map<int , int> cnt , last;
    int ans = n;
    for(int i = 0;i < n;i++) {
        cnt[a[i]]++;
        if(cnt[a[i]] > 1) {
            a[last[a[i]]] = -1;
            ans--;
            cnt[a[i]]--;
        }
        last[a[i]] = i;
    }
    cout << ans << ln;
    for(int i = 0;i < n;i++) {
        if(a[i] != -1) {
            cout << a[i] << ' ' ;
        }
    }
    cout << ln;
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
