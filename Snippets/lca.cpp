int lca(int a,int b)
{
    if(lv[a]>lv[b])
        swap(a,b);
    for(int i=p-1;i>=0;--i)
        if(level(dad[b][i])>=level(a))
            b=dad[b][i];
    if(a==b)
        return a;
    for(int i=p-1;i>=0;--i)
        if(dad[a][i]!=dad[b][i])
            a=dad[a][i],b=dad[b][i];
    return dad[a][0];
}

//precompute, make sure dad[n][0] is set to immediate parent of node
for(int j=1;j<p;++j)
    for(int i=0;i<n;++i)
        if(dad[i][j-1]>=0)
            dad[i][j]=dad[dad[i][j-1]][j-1];
