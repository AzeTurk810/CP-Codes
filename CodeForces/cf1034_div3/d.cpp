/*
Telebe of Adicto && Mamedov yani AzeTurk810.
I see humans but no humanity.
*/
#include <iostream>
#include <string>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

void solve() {
    int n , k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt1 = 0;
    for(char &c : s) {
        cnt1 += (c == '1');
    }
    if(cnt1 <= k) {
        cout << "Alice\n";
        return;
    }
    if(n >= 2 * k) {
        cout << "Bob" << ln;
        return ;
    } else {
        cout << "Alice" << ln;
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
