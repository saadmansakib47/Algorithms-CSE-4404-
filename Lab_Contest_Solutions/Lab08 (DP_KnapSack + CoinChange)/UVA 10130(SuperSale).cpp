#include<bits/stdc++.h>
using namespace std;
#define maxm 1005
int dp[maxm][105],price[maxm],wt[maxm],a,tc,n,m;
int F(int i,int x)
    {
        if(i>=n)
            return 0;
        if(dp[i][x]!=-1)
            return dp[i][x];
        int p=0;
        if(x+wt[i]<=a)
            p=max(F(i+1,x+wt[i])+price[i],F(i+1,x));
        else
            p=F(i+1,x);
        return dp[i][x]=p;
    }
int main()
{
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d %d",&price[i],&wt[i]);
        scanf("%d",&m);
        int p=0;
        for(int i=0;i<m;i++)
        {
            scanf("%d",&a);
            memset(dp,-1,sizeof(dp));
            p+=F(0,0);
        }
        printf("%d\n",p);
    }
    return 0;
}

