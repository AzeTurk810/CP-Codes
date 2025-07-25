/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
*/
#include <iostream>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

void solve() {
    int x , y;
    cin >> x >> y;
    for(int mask1 = 0;mask1 < D;mask1++) {
        for(int mask2 = 0;mask2 < D;mask2 ++) {
            for(int i = 0;i < D;i++) {
                if(((1LL << i) & mask1) ^ ((1LL << i) & mask2) != 1) {
                    continue;
                }
            }
        }
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
