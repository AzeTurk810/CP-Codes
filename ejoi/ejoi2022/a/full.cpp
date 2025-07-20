/*
Telebe of Adicto && AzeTurk810 yani AzeTurk810
I see humans but no humanity
*/
#include <algorithm>
#include <iostream>
#include <utility>
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

bool comp(const pair<int, int> &a , const pair<int , int> &b) {
    return a.second > b.second;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n) ;
    vector<pair<int, int>> cnt0(n + 1 , {0 , 0}) , cnt1(n + 1 , {0 , 0});
    for(int i = 0;i <= n;i++) {
        cnt0[i] = {i , 0};
        cnt1[i] = {i , 0};
    }
    for(int &i : a) {
        cin >> i;
    }
    for(int i = 0;i < n;i++) {
        if(i & 1) 
            cnt1[a[i]].second++;
        else
            cnt0[a[i]].second++;
    }
    int ans = n;
    sort(cnt0.begin() , cnt0.end() , comp);
    sort(cnt1.begin() , cnt1.end() , comp);
    for(int i = 0;i < min(13 , n);i++) {
        for(int j = 0;j < min(13 , n);j++) {
            int x = cnt0[i].first , y = cnt1[j].first;
            if(x == y)
                continue;
            ans = min(ans , cost(a , x , y));
            ans = min(ans , cost(a , y , x));
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
