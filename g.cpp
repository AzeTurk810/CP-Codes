/*
 * cds
Telebe of adicto yani AzeTurk810
without limits
*/
#include <cstdint>
#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

vector<vector<int>> g;
vector<int16_t> used;



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
        t[v] = min(t[(v << 1)] , t[(v << 1)|1]);
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
        return min(ask((v << 1) , l , mid , ql , qr),
                   ask((v << 1)|1 , mid + 1 , r , ql , qr));
    }
};
void dfs(int v) {
    used[v] = 2;
    for(int &to : g[v]) {
        if(!used[to])
            dfs(to);
        else if(used[to] == 2)
            last = to;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1 ; i <= n;i++) {
        cin >> a[i];
    }
    g.resize(n + 1);
    for(int i = 1;i <= n;i++) {
        g[i - a[i]].push_back(i);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
//   cin >> t;
    for(int cases = 0 ; cases < t;cases ++) {
        solve();
    }
}
