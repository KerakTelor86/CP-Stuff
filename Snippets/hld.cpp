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

struct segtr
{
    int n;
    vec<int> seg;

    segtr(vec<int> &x)
    {
        n=x.size();
        seg.assign(n<<2,0);
        build(x);
    }

    void build(vec<int> &x,int idx=0,int l=0,int r=-1)
    {
        if(r<0)
            r=n-1;
        if(l==r)
        {
            seg[idx]=x[l];
            return;
        }
        int m=l+((r-l)>>1),lc=(idx<<1)+1,rc=lc+1;
        build(x,lc,l,m);
        build(x,rc,m+1,r);
        seg[idx]=max(seg[lc],seg[rc]);
    }

    void upd(int u,int v,int idx=0,int l=0,int r=-1)
    {
        if(r<0)
            r=n-1;
        if(u<l||u>r)
            return;
        if(u==l&&u==r)
        {
            seg[idx]+=v;
            return;
        }
        int m=l+((r-l)>>1),lc=(idx<<1)+1,rc=lc+1;
        if(u<=m)
            upd(u,v,lc,l,m);
        else
            upd(u,v,rc,m+1,r);
        seg[idx]=max(seg[lc],seg[rc]);
    }

    int qry(int u,int v,int idx=0,int l=0,int r=-1)
    {
        if(r<0)
            r=n-1;
        if(u>r||v<l)
            return 0;
        if(u<=l&&v>=r)
            return seg[idx];
        int m=l+((r-l)>>1),lc=(idx<<1)+1,rc=lc+1;
        return max(qry(u,v,lc,l,m),qry(u,v,rc,m+1,r));
    }
};

// ch = chain
int ln;
vec<int> lv,sz,chid,chpos,chroot;
v2d<int> tr,dad,charr;
vec<segtr> ch;

int lca(int a,int b)
{
    if(lv[a]<lv[b])
        swap(a,b);
    for(int i=ln;i>=0;--i)
        if(dad[a][i]>=0&&lv[dad[a][i]]>=lv[b])
            a=dad[a][i];
    if(a==b)
        return a;
    for(int i=ln;i>=0;--i)
        if(dad[a][i]!=dad[b][i])
            a=dad[a][i],b=dad[b][i];
    return dad[a][0];
}

int qry_hld(int u,int v)
{
    int res=0;
    while(chid[u]!=chid[v])
    {
        res=max(res,ch[chid[u]].qry(0,chpos[u]));
        u=dad[chroot[chid[u]]][0];
    }
    int l=chpos[u],r=chpos[v];
    if(l>r)
        swap(l,r);
    res=max(res,ch[chid[u]].qry(l,r));
    return res;
}

int qry(int u,int v)
{
    int x=lca(u,v);
    return max(qry_hld(u,x),qry_hld(v,x));
}

void hld(int n,int p)
{
    if(chid[n]<0)
    {
        chid[n]=charr.size();
        chroot.push_back(n);
        charr.push_back({});
    }
    const int id=chid[n];
    chpos[n]=charr[id].size();
    charr[id].push_back(0);
    int mx=0,mxi=-1;
    for(auto &i:tr[n])
    {
        if(i==p)
            continue;
        if(sz[i]>mx)
        {
            mx=sz[i];
            mxi=i;
        }
    }
    for(auto &i:tr[n])
    {
        if(i==p||i==mxi)
            continue;
        hld(i,n);
    }
    if(mxi<0)
        return;
    chid[mxi]=id;
    hld(mxi,n);
}

void predfs(int n,int p,int l)
{
    lv[n]=l;
    sz[n]=1;
    for(auto &i:tr[n])
    {
        if(i==p)
            continue;
        dad[i][0]=n;
        predfs(i,n,l+1);
        sz[n]+=sz[i];
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    tr.assign(n,{});
    for(ln=0;(1<<ln)<n;++ln);
    dad.assign(n,vec<int>(ln+1,-1));
    sz.assign(n,0);
    lv.assign(n,0);
    chpos.assign(n,-1);
    chid.assign(n,-1);
    for(int i=1;i<n;++i)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        --a,--b;
        tr[a].push_back(b);
        tr[b].push_back(a);
    }
    predfs(0,-1,0);
    for(int i=1;i<=ln;++i)
        for(int j=0;j<n;++j)
            if(dad[j][i-1]>=0)
                dad[j][i]=dad[dad[j][i-1]][i-1];
    hld(0,-1);
    for(auto &i:charr)
        ch.push_back(segtr(i));
    int q;
    scanf("%d",&q);
    while(q--)
    {
        getchar();
        char t=getchar();
        int a,b;
        scanf("%d%d",&a,&b);
        if(t=='I') // add b to val[a-1]
            ch[chid[a-1]].upd(chpos[a-1],b);
        else // max on path between (a-1, b-1)
            printf("%d\n",qry(a-1,b-1));
    }
}

