/*
Telebe of Adicto && AzeTurk810 yani AzeTurk810
I see humans but no humanity
*/
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18
#define int i128
using i128 = __int128_t;


ostream& operator<<(ostream& os, __int128_t x) {
    if (x == 0) return os << "0";
    if (x < 0) {
        os << "-";
        x = -x;
    }
    string s;
    while (x > 0) {
        s += '0' + (x % 10);
        x /= 10;
    }
    reverse(s.begin(), s.end());
    return os << s;
}
istream& operator>>(istream& is, __int128_t& x) {
    string s;
    is >> s;
    x = 0;
    bool neg = false;
    int i = 0;
    if (s[0] == '-') {
        neg = true;
        i = 1;
    }
    for (; i < s.size(); i++) {
        if (!isdigit(s[i])) break;
        x = x * 10 + (s[i] - '0');
    }
    if (neg) x = -x;
    return is;
}



struct segmentTree {
    int N , Null_val;
    vector<int> t;

    segmentTree(int _n) {
        t.resize(_n * 4);
        N = _n;
         Null_val = 0;
    }

    void build(int v , int l , int r , vector<int> &a) {
        if(l == r) {
            t[v] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build((v << 1) , l , mid , a);
        build((v << 1)|1 , mid + 1 , r , a);
        t[v] = t[(v << 1)] + t[(v << 1)|1];
    }

    void upd(int v , int l , int r  , int &val , int &pos) {
        if(l == r) {
            t[v] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if(mid >= pos) upd((v << 1) , l , mid , val, pos);
        else upd((v << 1)|1 , mid + 1 , r , val , pos);
        t[v] = t[(v << 1)] + t[(v << 1)|1];
    }

    int ask(int v , int l , int r , int ql , int qr) {
        if(ql <= l && r <= qr) return t[v];
        if(ql > r || l > qr) return Null_val;
        int mid = (l + r) >> 1;
        return  (ask((v << 1) , l , mid , ql , qr) +
                   ask((v << 1)|1 , mid + 1 , r , ql , qr));
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &i : a)
        cin >> i;
    vector<int> ac = a;
    map<int ,int> mp;
    __int128_t sum = 0 , ans = 0;
    for(int i = 0;i < n;i++) {
        i128 cur = sum - mp[a[i] - 1] * (a[i] - 1) - mp[a[i] + 1] *(a[i] + 1);
        int say = i - mp[a[i] - 1] - mp[a[i] + 1];
        ans += say * a[i] - cur;
        sum += a[i];
        mp[a[i]]++;
    }
    cout << ans << ln;

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
