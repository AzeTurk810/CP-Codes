/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
*/
#include <algorithm>
#include <iostream>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

void solve() {
    int a , b , c;
    cin >> a >> b >> c;
    int mn = min(a - 1 , (c > b ? c - b + c - 1 : b - 1));
    b = (c > b ? c - b + c - 1 : b - 1);
    a--;
    if(a == mn && b == mn) {
        cout << 3 << ln;
    } else if(a == mn) {
        cout << 1 << ln;
    } else {
        cout << 2 << ln;
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
