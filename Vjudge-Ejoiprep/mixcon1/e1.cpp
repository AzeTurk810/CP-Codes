// Telebe of adicto yani AzeTurk810
//
// WHY ARE YOU STARING MY CODE Stranger ??!!
//
//GO AWAY AND DON T look my CODE if i don t know you or you are stalker !!!!(hrrr)
//
// here about me: I am alone of course, fun , ' , ' , love pyhcics , young(child) , love music , had birds , not a gamer , chess :) , dead to football , you are looking to code , ... ;
//
// why at 1 japon army march they say "the enemy geniral is a hero , an equal to no one. Both in glory and in victory
// the men that follow him are also breave , fearless wariors ..."?
// !!!!!!!!!!!!!Bu Kod Kohne kodumun Modifikasiyasidir!!!!!!!!!!!!!!!!
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

# define int ll
# define ln '\n'
# define ff first
# define ss second
# define INFll 1e18
# define MOD 998244353
#define max_N int(2e5 + 10)

int pow_2[max_N];

ll mult(ll a,ll b) {
    return (a * b) % MOD;
}

void build() {
    pow_2[0] = 1;
    for(int i = 1;i < max_N;i++) {
        pow_2[i] = mult(pow_2[i - 1] , 2);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    vector<int> prefix(n +  1, 0) , suffix(n + 2 , 0);
    for(int i = 1 ; i <= n ; i++) {
        cin >> v[i];
        prefix[i] = prefix[i - 1] + v[i];
    }
    for(int i= n ; i >= 1 ; i--) {
        suffix[i] = suffix[i + 1 ] + v[i];
    }
    int ans = 0 , mn = INFll , cur = 0;
    vector<int> &a = v;
    for(int i = 1 ; i <= n; i++) {
        cur += a[i];
        mn = min(mn , cur);
    }
    cur = 0;
    int pref = 0;
    ans = 1;
    if(mn >= 0) {
        cout << pow_2[n] << ln;
        return;
    }
    for(int i = 1;i <= n;i++) {
        cur += a[i];
        if(cur >= 0) {
            pref++;
        }
        if(mn == cur) {
            ans += pow_2[pref + (n - i)];
            ans %= MOD;
        }
    }
    ans--;
    cout << ans << ln;
} 


signed main() {
//    build();
    int t = 1;
    cin >> t;
    build();
    while(t--)solve();

}


