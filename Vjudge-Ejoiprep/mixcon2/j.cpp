/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
*/
#include <cassert>
#include <iostream>
#include <map>
#include <sched.h>
#include <set>
#include <utility>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

struct prob {
    int a , b , n , a0 , b0 , m , cnt1 = 0 , cnt2 = 0 , res;
    multiset<pair<int, int>> x , y;
    vector<pair<int , int>> nums;
    void init() {
        nums.clear();
        x.clear();
        y.clear();
        cnt1 = 0;
        cnt2 = 0;
        a0 = 0;
        b0 = 0;
    }

    void in() {
        cin >> a >> b >> n >> m;
        nums.resize(n);
        for(int i = 0;i < n;i ++) {
            int l , r;
            cin >> l >> r;
            x.insert({l , i});
            y.insert({r , i});
            nums[i] = {l , r};
        }
    }

    void d(int l) {
        l = a - l;
        auto it = x.lower_bound({l + 1, 0});
        while(it != x.end()) {
            auto ity = y.find({nums[it->second].second,it->second});
            assert(ity != y.end());
            y.erase(ity);
            auto cur = it++;
            res++;
            x.erase(cur);
        }
    }

    void r(int l) {
        auto it = y.end();
        l = b - l;
        if(it == y.begin()) {
            return;
        }
        it--;
        while(x.size()) {
            if(it->first <= l)
                break;
            auto itx = x.find({nums[it->second].first , it->second});
            assert(itx != x.end());
            res++;
            auto cur = it--;
            x.erase(itx);
            y.erase(cur);
        }
    }

    void u(int l) {
        l = a0 + l + 1;
        auto it = x.begin();
        while (it != x.end()) {
            if(it->first >= l)
                break;
            auto ity = y.find({nums[it->second].second , it->second});
            assert(ity != y.end());
            res++;
            auto cur = it++;
            x.erase(cur);
            y.erase(ity);
        }
    }

    void lr(int l) {
        l = b0 + l + 1;
        auto it = y.begin();
        while (it != y.end()) {
            if(it->first >= l ) 
                break;
            auto itx = x.find({nums[it->second].first , it->second});
            assert(itx != x.end());
            res++;
            auto cur = it++;
            x.erase(itx);
            y.erase(cur);
        }
    }

    void solve() {
        for(int i = 0;i < m;i++) {
            char tt;
            int l;
            cin >> tt >> l;
            res = 0;
            if(tt == 'L') {
                lr(l);
                b0 += l;
            } else if(tt == 'R') {
                r(l);
                b -= l;
            } else if(tt == 'U') {
                u(l);
                a0 += l;
            } else {
                d(l);
                a -= l;
            }
            if(i & 1)
                cnt2 += res;
            else
                cnt1 += res;
        }
        cout << cnt1 << ' ' << cnt2 << ln;
    }
} prob;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    for(int cases = 0 ; cases < t;cases ++) {
         prob.init();
         prob.in();
         prob.solve();
    }
}
// Just Imaginary
