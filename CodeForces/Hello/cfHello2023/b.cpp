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
    int n;
    cin >> n;
    if(n & 1) {
        if(n == 3) {
            cout << "NO\n";
        } else {
            int cr = n >> 1;
            cout << "YES\n";
            cr--;
            for(int i = 0;i < n;i++) {
                if(i & 1) {
                    cout << -(cr + 1) << ' ';
                } else {
                    cout << cr << ' ';
                }
            }
        }
        cout << ln;
        return;
    }
    cout  << "YES\n";
    for(int i = 0;i < n;i++) {
        if(i & 1) {
            cout << -1 << ' ';
        } else {
            cout << 1 << ' ';
        }
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
