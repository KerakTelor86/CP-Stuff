#include <bits/stdc++.h>

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("tune=native")

#define fi first
#define se second

using namespace std;

using ll=long long;
using ld=long double;

template<class T>
using vec=vector<T>;
template<class T>
using v2d=vector<vector<T>>;
template<class T>
using prq=priority_queue<T>;
template<class T>
using rpq=priority_queue<T,vector<T>,greater<T>>;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    vec<vec<pair<int,int>>> gr(n); //adjacency list (0-based)
    while(m--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c); //edge between a and b with weight c
        gr[a].push_back({b,c});
        gr[b].push_back({a,c});
    }
    int s,t; //source, sink
    scanf("%d %d",&s,&t);
    const int inf=1e9;
    vec<int> res(n,inf);
    rpq<pair<int,int>> q;
    q.push({0,s});
    res[s]=0;
    while(!q.empty())
    {
        int d=q.top().fi,c=q.top().se;
        if(c==t)
            break;
        q.pop();
        for(auto &i:gr[c])
            if(d+i.se<res[i.fi])
            {
                res[i.fi]=d+i.se;
                q.push({d+i.se,i.fi});
            }
    }
    printf("%d\n",res[t]);
}

