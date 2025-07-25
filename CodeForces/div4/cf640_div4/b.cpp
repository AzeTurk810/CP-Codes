//Desinged by AzeTurk810
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define pb push_back

int main()
{
    int t,n,k,n2;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int n1=n-k+1;n2=n-2*(k-1);
        if(n1>0 && n1%2==1)
        {
            cout<<"Yes"<<endl;
            for(int i=0;i<k-1;i++)cout<<1<<' ';
            cout<<n1<<endl;
            
        }
        
        else if(n2>0 && n2%2==0)
        {
            cout<<"Yes"<<endl;
            for(int i=0;i<k-1;i++)cout<<2<<' ';
            cout<<n2<<endl;
        }
        else
        cout<<"No"<<endl;
        
    }
    
}
