int n;
vector<ll> seg,lazy;

void propagate(int idx,int l,int r)
{
    if(!lazy[idx])
        return;
    int lc=(idx<<1)+1,rc=lc+1;
    seg[idx]+=(r-l+1)*lazy[idx];
    if(l!=r)
    {
        lazy[lc]+=lazy[idx];
        lazy[rc]+=lazy[idx];
    }
    lazy[idx]=0;
}

void update(int u,int v,int w,int idx=0,int l=0,int r=n-1)
{
    propagate(idx,l,r);
    if(u>r||v<l)
        return;
    if(u<=l&&v>=r)
    {
        lazy[idx]+=w;
        propagate(idx,l,r);
        return;
    }
    int lc=(idx<<1)+1,rc=lc+1,m=l+((r-l)>>1);
    update(u,v,w,lc,l,m);
    update(u,v,w,rc,m+1,r);
    seg[idx]=seg[lc]+seg[rc];
}

ll query(int u,int v,int idx=0,int l=0,int r=n-1)
{
    propagate(idx,l,r);
    if(u>r||v<l)
        return 0;
    if(u<=l&&v>=r)
        return seg[idx];
    int lc=(idx<<1)+1,rc=lc+1,m=l+((r-l)>>1);
    return query(u,v,lc,l,m)+query(u,v,rc,m+1,r);
}

