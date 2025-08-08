/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
Problem: E - Sereja and Brackets
Contest: SegmentTree-Classic
Judge: Virtual Judge
URL: https://vjudge.net/contest/736637#problem/E
Memory Limit: 1024
Time Limit: 1000
Start: Mon 04 Aug 2025 09:16:57 PM +04
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

struct node {
    int l , r , ans;
};

struct segmentTree {
    int N ;
    node Null_val;
    vector<node> t;

    node marge(node l , node r) {
        node res;
        int mn = min(l.r , r.l);
        res.ans = l.ans + r.ans + (mn << 1);
        res.l = l.l + r.l - mn;
        res.r = r.r + l.r - mn;
        return res;
    }

    segmentTree(int _n) {
        t.resize(_n * 4);
        N = _n;
    }

    void build(int v , int l , int r , string &a) {
        if(l == r) {
            t[v] = {(a[l] == ')') , (a[l] == '(') , 0};
            return;
        }
        int mid = (l + r) >> 1;
        build((v << 1) , l , mid , a);
        build((v << 1)|1 , mid + 1 , r , a);
        t[v] = marge(t[(v << 1)] , t[(v << 1)|1]);
    }

    node ask(int v , int l , int r , int ql , int qr) {
        if(ql <= l && r <= qr) return t[v];
        if(ql > r || l > qr) return Null_val;
        int mid = (l + r) >> 1;
        return marge(ask((v << 1) , l , mid , ql , qr),
                   ask((v << 1)|1 , mid + 1 , r , ql , qr));
    }
};

void solve() {
    string s;
    cin >> s;
    int q;
    cin >> q;
    int n = s.size();
    segmentTree t(n);
    t.build(1 , 0 , n - 1, s);
    t.Null_val = {0 , 0 , 0};
    while (q--) {
        int l , r;
        cin >> l >> r;
        l--;r--;
        cout << t.ask(1 , 0 , n - 1 ,l , r ).ans << ln;
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


