#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;

struct Query {
    int l, r, idx, block;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int m;
    cin >> m;
    int B = 80;
    vector<Query> Q(m);
    for (int i = 0; i < m; i++) {
        cin >> Q[i].l >> Q[i].r;
        --Q[i].l; // 0-based
        --Q[i].r;
        Q[i].idx = i;
        Q[i].block = Q[i].l / B;
    }
    sort(Q.begin(), Q.end(), [&](const Query &x, const Query &y) {
        if (x.block != y.block) return x.block < y.block;
        return (x.block & 1) ? (x.r > y.r) : (x.r < y.r);
    });

    multiset<ll> S;   // active values
    multiset<ll> D;   // differences between neighbors
    vector<ll> ans(m);

    auto add = [&](ll x) {
        if (S.empty()) {
            S.insert(x);
            return;
        }
        auto it = S.lower_bound(x);
        if (it != S.end())
            D.insert(abs(*it - x));
        if (it != S.begin()) {
            auto prv = prev(it);
            D.insert(abs(x - *prv));
            if (it != S.end())
                D.erase(D.find(abs(*it - *prv)));
        }
        S.insert(x);
    };

    auto remove = [&](ll x) {
        auto it = S.find(x);
        auto nxt = next(it);
        auto prv = (it == S.begin() ? S.end() : prev(it));
        if (nxt != S.end())
            D.erase(D.find(abs(*nxt - x)));
        if (prv != S.end())
            D.erase(D.find(abs(x - *prv)));
        if (nxt != S.end() && prv != S.end())
            D.insert(abs(*nxt - *prv));
        S.erase(it);
    };

    int curL = 0, curR = -1;
    for (auto &q : Q) {
        while (curL > q.l)      add(a[--curL]);
        while (curR < q.r)      add(a[++curR]);
        while (curL < q.l)      remove(a[curL++]);
        while (curR > q.r)      remove(a[curR--]);
        ans[q.idx] = (S.size() < 2 ? 0 : *D.begin());
    }

    for (ll v : ans)
        cout << v << '\n';

    return 0;
}

