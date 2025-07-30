/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
Problem: D. Mishka and Interesting sum
Contest: Codeforces Round 365 (Div. 2)
Judge: Codeforces
URL: https://codeforces.com/problemset/problem/703/D
Memory Limit: 256
Time Limit: 3500
Start: Wed 30 Jul 2025 12:49:09 PM +04
*/
#include <iostream>
#include <set>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

struct segmentTree {
    int N , Null_val;
    vector<int> t;

    segmentTree(int _n) {
        t.resize(_n * 4);
        N = _n;
    }

    void build(int v , int l , int r , vector<int> &a) {
        if(l == r) {
            t[v] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build((v << 1) , l , mid , a);
        build((v << 1)|1 , mid + 1 , r , a);
        t[v] = (t[(v << 1)] ^ t[(v << 1)|1]);
    }

    void upd(int v , int l , int r  , int &val , int &pos) {
        if(l == r) {
            t[v] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if(mid >= pos) upd((v << 1) , l , mid , val, pos);
        else upd((v << 1)|1 , mid + 1 , r , val , pos);
        t[v] = min(t[(v << 1)] , t[(v << 1)|1]);
    }

    int ask(int v , int l , int r , int ql , int qr) {
        if(ql <= l && r <= qr) return t[v];
        if(ql > r || l > qr) return Null_val;
        int mid = (l + r) >> 1;
        return     (ask((v << 1) , l , mid , ql , qr) ^
                   ask((v << 1)|1 , mid + 1 , r , ql , qr));
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int temp = 0;
    set<int> st;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    vector<int> b = a;
    // for(int i = 0;i < n;i++) {
        // a[i] ^= temp;
    // }
    segmentTree t(n) , t2(n);
    t.Null_val = t2.Null_val =  0;
    t2.build(1 , 0 , n - 1 , b);
    t.build(1 , 0 , n - 1 , a);
    int q;
    cin >> q;
    while(q--) {
        int l , r;
        cin >> l >> r;
        l--;r--;
        int q1 = t.ask(1 , 0 , n - 1, l , r) , q2 =  t2.ask(1 , 0 , n - 1, 0 , l - 1) , q3 =  t2.ask(1 , 0 , n - 1 , r + 1 , n - 1);
        cerr << q1 << ' ' << q2 << ' '<< q3 << endl;
        cout <<  (t.ask(1 , 0 , n - 1, l , r) ^ t2.ask(1 , 0 , n - 1, 0 , l - 1) ^ t2.ask(1 , 0 , n - 1 , r + 1 , n - 1)) << ln;   
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

