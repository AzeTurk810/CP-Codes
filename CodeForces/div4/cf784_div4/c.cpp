//Desinged by AzeTurk810
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define pb push_back

int main()
{
    int t,n;
    bool d;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<int>v(n);d=1;
        for(auto &i:v)cin>>i;
        for(int i=2;i<n;i+=2)
        {
            if(v[i] % 2!=v[i-2] %2)
            {d=0;break;}
        }
        if(d)
        {
            for(int i=3;i<n;i+=2)
            {
                if(v[i] %2!=v[i-2] %2)
                {d=0;break;}
            }
        }
        if(d)
        cout<<"Yes"<<endl;
        else
        cout<<"No"<<endl;
    }
}
