/*
Telebe of Adicto && AzeTurk810 yani AzeTurk810
I see humans but no humanity
*/
#include <iostream>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

void solve() {
    int l1 , r1 , l2 , r2;
    cin >> l1 >> r1 >> l2 >> r2;
    int a = l1 , b = l2;
    if(a == b) {
        if(l1 != r1)
         a++;
        else
         b++;
    }
    cout << a << ' ' << b << ln;
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
