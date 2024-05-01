#include <bits/stdc++.h>
using namespace std ;
int main()
{
    int t ;
    cin>> t;
    while(t--)
    {
        int n ;
        cin>>n ;
        string s ;
        cin>>s ;
        int arr[n] ;
        int count = 0 ;
        int st = -1 ;
        int en = 0 ;
        for(int i=0 ; i<n ; i++)
        {
            cin>>arr[i] ;
            if(s[i]=='1')
            {
                count++ ;
                if(st == -1)
                {
                    st = i ;
                }
                en = i ;
            }
        }
        int ans=0 ;
        for(int i=0 ; i<n-1 ; i++)
        {
            if(s[i]=='0' or s[i+1]=='0')
            {
                ans+=arr[i+1]-arr[i] ;
            }
        }
        if(count<2)
        {
            cout<<ans<<endl ;
        }
        else
        {
            int curr = 0 ;
            for(int i=st ; i<=en ; i++)
            {
                if(s[i]=='1')
                {
                    ans-=curr;
                    curr=0 ;
                }
                if(s[i+1]=='0' or s[i]=='0')
                {
                    curr=max(curr,arr[i+1]-arr[i]) ;
                }
            }
            cout<<ans<<endl ;
        }
    }
    return 0 ;
}
