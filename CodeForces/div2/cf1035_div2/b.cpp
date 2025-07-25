/*
Telebe of Adicto && AzeTurk810 yani AzeTurk810
I see humans but no humanity
*/
#include <algorithm>
#include <cmath>
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
    int px , py , qx , qy;
    cin >> px >> py >> qx >> qy;
    vector<int> a(n);
    int s = 0 , m = 0;
    for(int i = 0; i < n;i++) {
        cin >> a[i];
        s += a[i];
        m = max(m , a[i]);
    }

    long double dx = qx - px;
    long double dy = qy - py;
    long double D = sqrtl(dx * dx + dy * dy);
    long double mn = 0;
    if(m + m > s) {
        mn = (long double) (m - (s - m));
    }
    if(D <= (long double)s + 1e-12 && D + 1e-12 >= mn) {
        cout << "Yes" << ln;
    } else {
        cout << "No" << ln;
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
