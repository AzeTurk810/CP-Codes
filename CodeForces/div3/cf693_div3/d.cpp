/*
Telebe of adicto yani AzeTurk810
I see humans but no humanity
*/
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18
#define int ll

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &i : a) {
        cin >> i;
    }
    sort(a.begin() , a.end());
    int cur = 0;
    reverse(a.begin() , a.end());
    for(int i = 0;i < n;i++) {
        if((i & 1) == 0) {
            if((a[i] & 1) == 0) {
                cur -= a[i];
            }
        } else {
            if((a[i] & 1) == 1) {
                cur += a[i];
            }
        }
    }
    if(cur > 0) {
        cout << "Bob\n";
    } else if(cur == 0) {
        cout << "Tie\n";
    } else {
        cout << "Alice\n";
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
