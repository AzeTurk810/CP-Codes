/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
*/
#include <algorithm>
#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

void solve() {
    int n , k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    k--;
    int cur = a[k];
    sort(a.begin() , a.end());
    int i = 0;
    while(i + 1 < n && a[i + 1] <= cur) {
        i++;
    }
    if(i == n) {
        cout << "YES\n";
        return;
    }
    int cnt = a[i];
    for(int j = i + 1; j < n;j++) {
        if(a[j] - a[j - 1]  > cur) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
