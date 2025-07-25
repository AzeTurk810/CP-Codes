/*
Telebe of Adicto && AzeTurk810 yani AzeTurk810
I see humans but no humanity
*/
#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

void solve() {
    int n;
    cin >> n;
    vector<int> b(n) , a(n);
    for(int &i : b) 
        cin >> i;
    int l = 0 , r = n - 1;
    int ind = 0;
    while(l <= r) {
        a[ind++] = b[l++];
        if(l <= r) {
            a[ind++] = b[r--];
        }
    }
    for(int i = 0;i < n;i++) {
        cout << a[i] << ' ';
    }
    cout << ln;
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
