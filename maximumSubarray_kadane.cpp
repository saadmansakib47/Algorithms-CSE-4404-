#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    // int arr[]={-2,-3,4,-1,-2,1,5,-3};
    int maxSum=INT_MIN;
    int sum=0;
    int start, ansStart=-1, ansEnd=-1;
    for(int i=0;i<n;i++)
    {
        if(sum==0) start=i;

        sum+=arr[i];

        if(sum>maxSum)
        {
            maxSum=sum;
            ansStart=start;
            ansEnd=i;
        }
    
        if(sum<0)
        {
            sum=0;
        }
    }


    cout<<endl<<maxSum;
}