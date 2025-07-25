/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
*/
#include <algorithm>
#include <iostream>
#include <numeric>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18
#define int ll

void solve() {
    int a , b , k;
    cin >> a >> b >> k;
    int g = gcd(a , b);
    if(max(a , b) <= k || max(a / g , b / g) <= k ) {
        cout << 1 << ln;
        return;
    }
    cout << 2 << ln;

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
