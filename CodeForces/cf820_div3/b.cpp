/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
*/
#include <algorithm>
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
    string ans;
    for(int i = n - 1;i >= 0;i--) {
        if(s[i] == '0') {
            int ch = (s[i - 2] - '0') * 10 + s[i - 1] - '0' + 'a' - 1;
            ans.push_back(char(ch));
            i -= 2;
        } else {
            ans.push_back(char(int(s[i]) - '0' + 'a' - 1));
        }
    }
    reverse(ans.begin() , ans.end());
    cout << ans << ln;
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
