/*
Telebe of Adicto && Mamedov yani AzeTurk810.
I see humans but no humanity.
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
    int n , j , k;
    cin >> n >> j >> k;
    vector<int> a(n);
    for(int &i : a)
        cin >> i;
    int aj = a[j - 1];
    int cnt = 0;
    int mx = *max_element(a.begin() , a.end());
    if(mx == aj) {
        cout << "yes\n";
        return;
    }

    cout << (k == 1 ? "No\n" : "Yes\n") ;
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
