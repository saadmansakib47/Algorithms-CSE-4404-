#include<bits/stdc++.h>
using namespace std ;

long long max(long long a, long long b)
{
    return (a>b)? a:b ;
}

long long max(long long a, long long b, long long c)
{
    return max(max(a,b),c);
}

long long maxCrossingSum(long long arr[], long long l,long long m,long long r )
{
    long long sum = 0 ;
    long long left_sum = long INT_MIN ;
    for(long long i=m ; i>=l ; i-- )
    {
        sum = sum + arr[i] ;
        if (sum>left_sum)
        {
            left_sum = sum ;
        }
    }

    sum = 0 ;
    long long right_sum = long INT_MIN ;
    for(long long i=m ; i<=r ; i++)
    {
        sum = sum + arr[i] ;
        if(sum> right_sum)
        {
            right_sum = sum ;
        }
    }

    return max(left_sum + right_sum - arr[m], left_sum, right_sum) ;
}

long long maxSubarraysum( long long arr[], long long l, long long r)
{
    if(l>r)
    {
        return long INT_MIN ;
    }
    if(l==r)
    {
        return arr[l] ;
    }
    long long m=(l+r)/2 ;

    return max(maxSubarraysum(arr,l,m-1), maxSubarraysum(arr, m+1, r), maxCrossingSum(arr,l,m,r)) ;
}

int main()
{
    int a ;
    cin>>a ;
    for(int i = 0 ; i<a ; i++)
    {
        long long n ;
        cin>>n ;
        long long arr[n] ;
        long long M_Sum = 0 ;
        long long a = INT_MIN ;

        for(long long i=0 ; i<n ; i++)
        {
            cin>>arr[i] ;
        }
        for(long long i=0 ; i<n ; i++)
        {
            if(arr[i]>0)
            {
                M_Sum = M_Sum + arr[i] ;
            }
            else
            {
                a=max(a,arr[i]) ;
            }
        }
        if(M_Sum<=0)
        {
            M_Sum=a ;
        }

        long long max_sum = maxSubarraysum(arr,0,n-1) ;
        cout<<max_sum<<" "<<M_Sum<<endl ;
    }
}





