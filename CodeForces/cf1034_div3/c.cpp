/*
Telebe of Adicto && Mamedov yani AzeTurk810.
I see humans but no humanity.
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 0;i < n;i++) {
        cin >> a[i + 1];
    }
    vector<int> sufmax(n + 2 , -INFi);
    for(int i = n ;i >= 1;i--) {
        sufmax[i] = max(a[i] , sufmax[i + 1]);
    }
    string ans(n , '0');
    int mn = INFi;
    for(int i = 0;i < n;i++) {
        bool okl = (a[i + 1] <= mn);
        bool okr = (a[i + 1] >= sufmax[i + 2]);
        if(okl || okr) 
            ans[i] = '1';
        mn = min(mn , a[i + 1]);
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
