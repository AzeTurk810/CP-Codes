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
    string s;
    cin >> s;
    int cnt = 0 , ans = 0;
    for(int i = 0;i < n;i++) {
        if(s[i] == 'x') {
            cnt++;
            if(cnt == 3) {
                cnt--;
                ans++;
            }
        } else {
            cnt = 0;
        }
    }
    cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
//    cin >> t;
    for(int cases = 0 ; cases < t;cases ++) {
        solve();
    }
}
// Just Imaginary
