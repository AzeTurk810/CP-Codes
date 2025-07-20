/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
*/
#include <iostream>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

void solve() {
    int a , b , c , x , y;
    cin >> a >> b >> c >> x >> y;
    if(a + c < x) {
        cout << "NO\n";
        return;
    }
    int cc = c;
    c = min(c , c + a - x);
    if(b + c < y) {
        cout << "NO\n";
        return;
    } 
    cout << "YES\n";
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
