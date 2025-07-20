// writed by Ekber_Ekber and Osman_112 at 01:03 AM - 03:03 AM
// Devraldi AzeTurk810 Sabah at 18:58 
#include <bits/stdc++.h>
#define GOOD_LUCK ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long ;
#define int long long
#define endl "\n"
#define ff first
#define ss second
#define pb push_back
#define all(v) v.begin(), v.end()
using namespace std;

constexpr int MAX = 2e+5 + 1, INF = 2e+7, MOD = 1e+9 + 7, K = 31;
int t[MAX * 2][10][10];
int lazy[MAX * 2][10];
int pw[10];
vector <int> a;

void build(int v, int tl, int tr) {
	if (tl == tr) {
		int x = a[tl], cnt=1;
		while (x > 0) {
			t[v][cnt][x % 10]++;
			x /= 10;
			cnt++;
		}
		return;
	}
	int tm = (tl + tr) / 2;
	build(v*2, tl, tm);
	build(v*2+1, tm+1, tr);
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			t[v][i][j] = t[v * 2][i][j] + t[v * 2 + 1][i][j];
		}
	}
}

void push(int v) {
	bool ok = 1;
	for (int i = 0; i < 10; i++) {
		if (lazy[v][i] != 0) ok = 0;
	}
	if (ok) return;
	// cout << endl << "Osman deyirki yeriyin gedin!" << endl;
	for (int i = 0; i < 10; i++) {
		if (lazy[v][i] == -1) continue;
		int k = lazy[v][i];
		for (int j = 0; j < 10; j++) {
			t[v*2][j][k] += t[v*2][j][i];
			t[v*2][j][i] = 0;
			t[v*2+1][j][k] += t[v*2+1][j][i];
			t[v*2+1][j][i] = 0;
		}
	}
	for (int i=0; i < 10; i++) {
		if(lazy[v][i] != -1){
			lazy[v*2][i] = lazy[v][i];
			lazy[v*2+1][i] = lazy[v][i];
			lazy[v][i] = -1;
		}
	}
}

void find(int v, int tl, int tr, int l, int r, ll (&res)[10][10]) {
  if (l > r) return;
  if (tl == l && tr == r) {
    for (int i = 0; i < 10; i++)
      for (int j = 0; j < 10; j++)
        res[i][j] += t[v][i][j];
    return;
  }
  push(v);
  int tm = (tl + tr) / 2;
  find(v * 2, tl, tm, l, min(r, tm), res);
  find(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, res);
}

void upd(int v, int tl, int tr, int l, int r, int x, int y) {
	if (l > r || x == y) return;
	if (tl == l && tr == r) {
		for (int i=0; i < 10; i++) {
			t[v][i][y] += t[v][i][x];
			t[v][i][x] = 0;
			// cout << "Osman deyirki bu kod = very very many many bugs";
		}
		lazy[v][x] = y;
		return;
	}
	// cout << "Osmandan Salamlar.";
	push(v);
	int tm = (tl + tr) / 2;
	upd(v*2, tl, tm, l, min(r, tm), x, y);
	upd(v*2+1, tm+1, tr, max(l, tm+1), r, x, y);
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			t[v][i][j] = t[v * 2][i][j] + t[v * 2 + 1][i][j];
		}
	}
}

ll ask(ll x[10][10]) {
	ll res=0;
	for (int i=1; i < 10; i++) {
		for (int j=1; j < 10; j++) {
			res += j * pw[i - 1] * x[i][j];
		}
	}
	return res;
}

void _() {
	int n, q;
	cin >> n >> q;
	a.resize(n);
	for (int &i : a) cin >> i;
	build(1, 0, n-1);
	pw[0] = 1;
	for(int i = 1; i < 10; i++)
		pw[i] = pw[i - 1] * 10;
	memset(lazy, -1, sizeof(lazy));
	while (q--) {
		int d;
		cin >> d;
		if (d == 1) {
			int l, r, x, y;
			cin >> l >> r >> x >> y;
			--l, --r;
			upd(1, 0, n-1, l, r, x, y);
		}
		else {
			int l, r;
			cin >> l >> r;
			--l, --r;
			ll res[10][10] = {};
      find(1, 0, n - 1, l, r, res);
			// for (int i=1; i < 10; i++) {
			// 	for (int j=0; j < 10; j++) {
			// 		cout << res[i][j] << ' ';
			// 	}
			// 	cout << endl;
			// }
			// cout << endl;
			cout << ask(res) << endl;
		}
	}
}

signed main() {

	GOOD_LUCK

	int tests=1;
	// cin >> tests;
	for (int i=1; i <= tests; i++) {
		_();
		// cout << endl;
	}

	return 0;
}

/*
5 2
38 43 4 12 70
1 1 3 4 8
2 2 4


*/
