/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
*/
#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

const int n = 7;

void solve() {
    vector<int> sums(n);
    for(int i = 0;i < n;i++) {
        cin >> sums[i];
    }
    int a[3];
    a[0] = sums[0];
    a[1] = sums[1];
    a[2] = sums[n - 1] - a[0] - a[1];
    cout << a[1] << ' ' << a[0] << ' ' << a[2] << ln;
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
