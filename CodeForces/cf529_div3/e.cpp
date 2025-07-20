/*
Telebe of Adicto && AzeTurk810 yani AzeTurk810
I see humans but no humanity
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18
#define int ll 

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n & 1) {
        cout << 0 << ln;
        return;
    }
    s = "$" + s;
    vector<pair<int, int>> suffix(n + 3);
    suffix[n + 1] = {0 , 0};
    int cur = 0;
    for(int i = n ;i >= 1;i--) {
        suffix[i].first = suffix[i + 1].first;
        cur -= (s[i] == ')' ? -1 : 1);
        suffix[i].first = min(suffix[i].first , cur);
        suffix[i].second = cur;
    }
    int ans = 0;
    cur = 0;
    for(int i = 1;i <= n;i++) {
        cur -= (s[i] == ')' ? -1 : 1);
        if(cur >= 0 && cur - suffix[i + 1].second == 0 && cur + suffix[i + 1].first >= 0) {
//            cerr << i << ' ' << s[i] << ' ' << suffix[i + 1].second + cur << ' ' << suffix[i + 1].first + cur << ln;
            ans++;
        }
        cur += (s[i] == ')' ? -1 : 1);
        cur += (s[i] == ')' ? -1 : 1);
        if(cur < 0) 
            break;
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
