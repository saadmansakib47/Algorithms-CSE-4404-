#include <bits/stdc++.h>
using namespace std;
int main()
{
    long int n ; cin>> n ;
    string arr[n] ;
    for(long int i=0 ; i<n/2 ; i++)
    {
        int x ; cin >> x ;
        string s ; cin >> s ;
        arr[x] = arr[x] + "-" + " " ;
    }

    for(long int i=n/2;i<n; i++)
    {
        int x ; cin>> x ;
        string s ; cin>>s ;
        arr[x] = arr[x] + s + " " ;
    }

    for(int i=0 ; i<n ; i++)
    {
        cout<<arr[i] ;
    }
    return 0 ;
}
