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

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> pr(n);
    for(int i = 0;i < n;i++) {
        cin >> pr[i].first >> pr[i].second;
    }
    sort(pr.begin() , pr.end());
    int mx = pr[0].second;
    for(int i = 1;i < n;i ++) {
        if(pr[i].second < mx) {
            cout << "NO" << ln;
            return;
        }
        mx = max(mx , pr[i].second);
    }
    cout << "YES\n";
    string ans;
    int x = 0 , y = 0;
    for(const auto &[l , r] : pr) {
        while(x < l) {
            x++;
            ans.push_back('R');
        }
        while(y < r) {
            y++;
            ans.push_back('U');
        }
    }
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
