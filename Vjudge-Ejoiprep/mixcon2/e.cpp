/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
*/
#include <algorithm>
#include <cassert>
#include <iostream>
#include <istream>
#include <map>
#include <set>
#include <utility>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18


struct point {
    int l , r;
    bool operator <(const point b) const {
        if(l == b.l)
            return r < b.r;
        return l < b.l;
    }
};

struct point2 {
    int l , r , ind;
    bool operator <(const point2 b) const {
        if(l == b.l)
            return r < b.r;;
        return l < b.l;
    }
};

bool comp(const point2 &l ,const point2 &r) {
    if(l.l != r.l) 
        return l.l < r.l;
    return l.r > r.r;           // R uzaqda olmayanda hell sehv verir cunki birinci yaxindakinin ansini artirmir , bu meni uzdu , 30 deq
}

bool comp2(const point2 &l ,const point2 &r) {
    if(l.r != r.r) {
        return l.r > r.r;
    }
    return l.l < r.l;
}

struct prob {
    int n;
    vector<point> a;
    vector<int> ans;
    void init() {
        a.clear();
        n = 0;
        ans.clear();
    }
    void in() {
        cin >> n;
        ans.assign(n , false);
        a.resize(n);
        for(auto &[l , r] : a) {
            cin >> l >> r;
        }
    }

    void solve(vector<point> a) {
        vector<point2> st;
        for(int i = 0;i < n;i++) {
            st.push_back({a[i].l , a[i].r , i});
        }
        sort(st.begin() , st.end() , comp);
        set<int> nebilim;
        for(int i = 0;i < n;i++) {
            auto it = nebilim.lower_bound(st[i].r);
            if(it != nebilim.end())
                ans[st[i].ind] += *it - st[i].r;
            nebilim.insert(st[i].r);
        }
    }

    void solve2(vector<point> a) {
        vector<point2> st;
        for(int i = 0;i < n;i++) {
            st.push_back({a[i].l , a[i].r , i});
        }
        sort(st.begin() , st.end() , comp2);
        set<int> nebilim;
        for(int i = 0;i < n;i++) {
            auto it = nebilim.lower_bound(-st[i].l);
            if(it != nebilim.end())
                ans[st[i].ind] += *it + st[i].l;
            nebilim.insert(-st[i].l);
        }
    }

    void solve() {
        solve(a);
        solve2(a);
        map<point , int> cnt;
        cnt.clear();
        for(int i = 0;i < n;i ++) {
            cnt[a[i]]++;
        }
        for(int i = 0;i < n;i++) {
            if(cnt[a[i]] > 1) {
                ans[i] = 0;
            }
        }
        for(int i = 0;i < n;i++) {
            cout << ans[i] << ln;
        }
        cout << ln;
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
