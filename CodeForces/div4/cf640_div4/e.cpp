// Telebe of adicto yani AzeTurk810
/*
    Author:             AzeTurk810
    Licance:            open source(only authors name must be in code)

*/
/*
    Ascii art
    ________  ________  _______  _________  ___  ___  ________  ___  __    ________    _____  ________
    |\   __  \|\_____  \|\  ___ \|\___   ___\\  \|\  \|\   __  \|\  \|\  \ |\   __  \  / __  \|\   __  \
    \ \  \|\  \\|___/  /\ \   __/\|___ \  \_\ \  \\\  \ \  \|\  \ \  \/  /|\ \  \|\  \|\/_|\  \ \  \|\  \
     \ \   __  \   /  / /\ \  \_|/__  \ \  \ \ \  \\\  \ \   _  _\ \   ___  \ \   __  \|/ \ \  \ \  \\\  \
      \ \  \ \  \ /  /_/__\ \  \_|\ \  \ \  \ \ \  \\\  \ \  \\  \\ \  \\ \  \ \  \|\  \   \ \  \ \  \\\  \
       \ \__\ \__\\________\ \_______\  \ \__\ \ \_______\ \__\\ _\\ \__\\ \__\ \_______\   \ \__\ \_______\
        \|__|\|__|\|_______|\|_______|   \|__|  \|_______|\|__|\|__|\|__| \|__|\|_______|    \|__|\|_______|
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <map>
#include <bitset>
#include <queue>
//  #include <bits/stdc++.h>
#include <map>
//#include <unordered_map>

using namespace std;
//using ll= long long;
//using ull=unsigned long long;

typedef long long ll;
typedef unsigned long long ull;

# define vint vector<int>
# define vull vector<unsigned long long>
# define sint set<int>
# define vpri vector<pair<int,int>>
# define vll vector<long long>
# define vbl vector<bool>
# define vvint vector<vector<int>>
# define vvll vector<vector<long long>>

/* Other defines*/
# define qint queue<int>

//# define endl '\n'
# define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
# define range(a,b,c) for(int i=a;i<b;i+=c)
# define ranger(a,b,c) for(int r=a;r<b;r+=c)
# define arange(a,b,c) for(int i=a;i>b;i-=c)
# define bend(x) (x).begin(),(x).end()
# define pb push_back
# define sortv(v) sort((v).begin() , (v).end());
# define fori(x) for(int i=0;i<x;i++)
# define forj(y) for(int j=0;j<y;j++)
# define forn(x,c) for(int i=0;i<n;i+=c)
# define ff fir st
# define ss second
# define INFi 1e9
# define INFll 1e18
# define printfprs(v) for(int alma = 0;alma<(v).size();alma++){cout<<(v)[alma].ff<< ' '<<(v)[alma].ss<<endl;};
# define printfv(v) {for(int alol = 0 ; alol < (v).size() ; alol++){cout<<(v)[alol]<<' ';}cout << endl;}
//# define int long long

int lcm(int a, int b)
{
   int y  = __gcd(a , b);
   return ((a * b ) / y);
}

ll find_digits(int n)
{
    int res = 0;
    while(n > 0)
    {
        n/= 10;
        res++;
    }
    return res;
}

ll find_how_many_3_need(int n)
{
    int res = 0;
    while(n > 0)
        res++,n/=3;
    return res;
}

/*ll solve(ll a ,ll b)
{
    if(a > n || b > n)return 0;
    //cout << a << ' ' << b << ' ' << dp[a][b] <<  ' ' <<  ans << "\n";
    if(a == n && b == n){ans++;return 1;}
    if(dp[a][b] != -1){ans += dp[a][b];return dp[a][b];}
    else
    {
        dp[a][b] = (solve(a + 1 , b) + solve(a , b+ 1))%MOD;
        ans += dp[a][b] %MOD;
        return dp[a][b];
    }
}*/

ll modular_pow(ll base , ll pow ,const ll &MOD)
{
    if(pow == 0)return 1;
    ll ret = modular_pow(base , pow / 2,MOD);
    ret = (ret * ret )%MOD;
    if(pow % 2)ret = (ret * base)%MOD;
    return ret;
}
/*
ll inver(ll x,ll y)
{
    ll ret=(f[y]*rev_f[x])%MOD;
    ret=(ret*rev_f[y-x])%MOD;
    ret=(ret*(ll)2)%MOD;
    return ret;
}*/

ll f(ll n ,const ll &m)
{
    return n - n / m;
}

vint v;
int n , mx = -INFi;

bool used[int(1e5 + 7)];

void solve()
{
    cin >> n;
    v.resize(n);
    map<int,int>mp;
    fori(n)
    {
        cin >> v[i];
        mx = max(mx , v[i]);
        mp[v[i]] ++;
    }
    //cout << 2 << endl;
    /*int l = 0 , r= 0 , cnt = 0;
    while(r < n)
    {
        if(cnt < mx)
        {
            cnt += v[r];
            r++;
        } else {
            cnt -= v[l];
            l++;
        }                   olmasa bu hellin davami
    }*/
    ll sum = 0;//cout << 11 << endl;
    for(int i = 0 ; i< n - 1 ;i++)
    {
       // cout << sum << '|' << i << ' ' << n<< endl;
        sum = v[i] + v[i + 1] ;
        used[sum] = true;
        for(int j = i + 2 ; j < n ;j++)
        {
            sum += v[j];
            //cout << sum << ' ' << j << endl;
            if(sum <= 1e5)used[sum] = true;else break;
        }
    }
    //cout << 3 << endl;
    ll res =0;
    for(int i = 1 ;i <= 1e5;i++)
    {
        if(used[i] == 1)
        {
            if(mp[i] >= 1)
            res += mp[i];
        }
        used[i] = 0; // novbeti tsk bugu :( 2 3 saat gormedim
    }
    cout << res << "\n";
}
signed main()
{
    //fastio;
    //cout << 1 << endl;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

