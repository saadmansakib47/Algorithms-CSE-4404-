#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e6 + 10 ;

ll par[N] ;
ll siz[N] ;
ll vis[N] ;
vector<ll>adj[N] ;

void make(ll v)
{
    par[v]=v ;
    siz[v]=1 ;
}

int find(ll v)
{
    if(v == par[v] )
    {
        return v ;
    }
    return par[v] = find(par[v]);
}

void Union(ll a, ll b)
{
    a= find(a) ;
    b =find(b) ;
    if(a!=b)
    {
        if(siz[a]<siz[b])
        {
            swap(a,b);
        }
        par[b]=a  ;
        siz[a] = siz[a] + siz[b] ;
    }
}

int main()
{
    ll n,m ;
    cin>>n>>m ;
    vector <pair<ll,pair<ll,ll>>>edges;

    bool vis[n+1] ;

    for(int i=1 ; i<=n ; i++)
    {
        make(i) ;
    }
    for(int i=0 ; i<m ; i++)
    {
        ll u,v ;
        ll w ;
        cin>>u>>v>>w ;

        edges.push_back({w,{u,v}}) ;
    }
    sort(edges.begin(), edges.end()) ;

    ll tot_cost = 0 ;

    vector<pair<ll,ll>>MSTedges ;

    for(auto &edge : edges)
    {
        ll wt = edge.first ;
        ll u = edge.second.first ;
        ll v = edge.second.second ;

        if(find(u)==find(v))
        {
            continue ;
        }
        Union(u,v) ;
        tot_cost+= wt ;

        MSTedges.push_back({u,v}) ;
    }
    ll p=find(1) ;
    bool f = 0 ;

    for(int i=2; i<=n ; i++)
    {
        if(find(i)!=p)
        {
            f=1 ;
            break ;
        }
    }

    if(f)
    {
        cout<<"IMPOSSIBLE"<<endl ;
    }
    else
    {
        cout<<tot_cost<< endl ;
    }
}






