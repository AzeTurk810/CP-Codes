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
    int n , m;
    cin >> n >> m;
    vector<ll> a(n + 1) , prefix(n + 1);
    prefix[0] = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
    }
    for(int i = 0;i < m;i++) {
        ll b;
        cin >> b;
        int ind = lower_bound(prefix.begin() , prefix.end() , b) - prefix.begin();
        cout << ind << ' ' << b - prefix[ind - 1] << ln;;
    }
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
