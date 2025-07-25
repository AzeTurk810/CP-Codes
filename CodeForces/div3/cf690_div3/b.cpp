/*
Telebe of Adicto && AzeTurk810 yani AzeTurk810
I see humans but no humanity
*/
#include <cassert>
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
    string s;
    cin >> s;
    bool ok = false;
    for(int i = 1;i <= 3;i++) {
        string sl = s.substr(0,i);
        string sr = s.substr(n + i - 4);
        string t = sl + sr;
        assert(t.size() == 4);
        if(t == "2020") {
            ok = true;
            break;
        }
    }
    if(s.substr(0 , 4) == "2020" || s.substr(n - 4) == "2020" || ok) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
