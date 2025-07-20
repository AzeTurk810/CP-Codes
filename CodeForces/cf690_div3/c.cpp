/*
Telebe of Adicto && AzeTurk810 yani AzeTurk810
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
   int x;
   cin >> x;
   string n;
   for(int i = 9;i >= 1;i--) {
       if(x - i >= 0) {
           x -= i;
           n.push_back(i + '0');
       }
   }
   if(x) {
       cout << "-1\n";
   } else {
       reverse(n.begin() , n.end());
       cout << n << ln;
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
