/*
Telebe of Adicto && AzeTurk810 yani AzeTurk810
I see humans but no humanity
*/
#include <iostream>
#include <utility>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

bool ff(pair<int, int> a , int val) {
    return a.first == val || a.second == val;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> kids(n);
    for(auto &[l , r] : kids) {
        cin >> l >> r;
    }
    vector<int> p(n);
    p[0] = 1;
    int prev = (ff(kids[kids[0].first - 1] , kids[0].second) ? kids[0].first : kids[0].second);
    p[1] = prev;
    int cur = (kids[0].first == prev ? kids[0].second : kids[0].first);
    p[2] = cur;
    for(int i = 3;i < n;i++) {
        int cprev = cur;
        int ccur = (kids[prev - 1].first == cur ? kids[prev - 1].second : kids[prev - 1].first);
        cur = ccur;
        prev = cprev;
        p[i] = cur;
    }
    for(int i = 0;i < n;i++) {
        cout << p[i] << ' ';
    }
    cout << '\n';
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
