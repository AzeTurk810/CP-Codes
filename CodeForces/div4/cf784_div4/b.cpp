//Desinged by AzeTurk810 with totorial
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define pb push_back

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++)
        cin>>v[i];
        bool b=1;
        sort(v.begin(),v.end());
        for(int i=0;i<n-2;i++)
        {
            if(v[i]==v[i+1] && v[i+1]==v[i+2])
            {
                b=0;cout<<v[i]<<endl;break;
            }
        }
        if(b)
        cout<<-1<<endl;
    }
}
