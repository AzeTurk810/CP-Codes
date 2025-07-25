//Desinged by AzeTurk810
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define pb push_back

int main()
{
    int t,a;
    cin>>t;
    while(t--)
    {
        cin>>a;
        int say=1;
        vector<ll>v;
        while(a>0)
        {
            if(a%10!=0)
            v.pb(a%10 * say);
            a/=10;
            say*=10;
        }
        cout<<v.size()<<endl;
        for(int i=0;i<v.size();i++)
        cout<<v[i]<<' ';
        cout<<endl;
    }
    
}
