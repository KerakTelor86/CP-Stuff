#include <bits/stdc++.h>

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("tune=native")

#define vec vector
#define prq priority_queue
#define fi first
#define se second

using namespace std;

using ll=long long;
using ld=long double;

int n,s,t;
vec<vec<int>> gr;
vec<vec<int>> flow;
vec<int> prn;
const int inf=1e9;

int aug_path()
{
    prn.assign(n,-1);
    prn[s]=-2;
    queue<pair<int,int>> q;
    q.push({s,inf});
    while(!q.empty())
    {
        int c=q.front().fi,d=q.front().se;
        q.pop();
        for(auto &i:gr[c])
        {
            if(prn[i]!=-1||!flow[c][i])
                continue;
            prn[i]=c;
            int temp=min(d,flow[c][i]);
            if(i==t)
                return temp;
            q.push({i,temp});
        }
    }
    return 0;
}

int main()
{
    int tt,tc=0;
    scanf("%d",&tt);
    while(tt--)
    {
        scanf("%d",&n);
        flow.assign(n,vec<int>(n));
        gr.assign(n,{});
        int m;
        scanf("%d%d%d",&s,&t,&m);
        --s,--t;
        while(m--)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            --a,--b;
            gr[a].push_back(b);
            gr[b].push_back(a);
            flow[a][b]+=c;
            flow[b][a]+=c;
        }
        int res=0;
        while(1)
        {
            int temp=aug_path();
            if(!temp)
                break;
            res+=temp;
            int pos=t;
            while(pos!=s)
            {
                int p=prn[pos];
                flow[p][pos]-=temp;
                flow[pos][p]+=temp;
                pos=p;
            }
        }
        printf("Case %d: %d\n",++tc,res);
    }
}
