/*
Telebe of Adicto && AzeTurk810 yani AzeTurk810
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

int cost(vector<int> a , int x , int y) {
    int _n = a.size();
    int res = 0;
    // x cut indekslere qoyulacaq
    // y tek insekslere qoyulacaq
    // indeksleme 0 dan
    for(int i = 0;i < _n;i++) {
        if(i & 1) {
            if(a[i] == y) {
                continue;
            } else if(a[i] == x) {
                if(i + 1 < _n) {
                    if(a[i + 1] == y) {
                        res += 2;
                        a[i + 1] = INFi;
                        a[i] = y;
                        continue;
                    }
                } 
                a[i] = y;
                res++;
            } else {
                res++;
                a[i] = y;
            }
        } else {
            if(a[i] == x) {
                continue;
            } else if(a[i] == y) {
                if(i + 1 < _n) {
                    if(a[i + 1] == x) {
                        res += 2;
                        a[i + 1] = INFi;
                        a[i] = x;
                        continue;
                    }
                }
                a[i] = x;
                res++;
            } else {
                res ++ ;
                a[i] = x;
            }
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n) , cnt0(n + 1 , 0) , cnt1(n + 1 , 0);
    for(int &i : a) {
        cin >> i;
    }
    for(int i = 0;i < n;i++) {
        if(i & 1) 
            cnt1[a[i]]++;
        else
            cnt0[a[i]]++;
    }
    int z = (n + 1) >> 1 , o = n >> 1;
    int ans = n;
    for(int i = 0;i < n;i++) {
        for(int j = i + 1 ; j < n;j++) {
            if(a[i] == a[j]) 
                continue;
            ans = min({ans , cost(a , a[j] , a[i]) , cost(a , a[i] , a[j])});
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
