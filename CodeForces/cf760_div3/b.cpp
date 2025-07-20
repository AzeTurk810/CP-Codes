/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
*/
#include <iostream>
#include <string>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

void solve() {
    int n;
    cin >> n;
    string res;
    cin >> res;
    bool ok = false;
    for(int i = 1;i < n - 2;i++) {
        string k;
        cin >> k;
        if(k[0] != res.back()) {
            ok = true;
            res.push_back(k[0]);
        }
        res.push_back(k[1]);
    }
    if(!ok)
        res.push_back('a');
    cout << res << ln;
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
