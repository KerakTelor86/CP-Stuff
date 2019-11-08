using mat=vector<vector<ll>>;

mat emp=identity_matrix();

mat mul(mat a,mat b)
{
    if(a[0].size()!=b.size())
        return emp;
    int y=a.size(),x=b[0].size(),n=b.size();
    mat res(y,vector<ll>(x));
    for(int i=0;i<y;++i)
        for(int k=0;k<n;++k)
            for(int j=0;j<x;++j)
                res[i][j]=(res[i][j]+(a[i][k]*b[k][j])%m)%m;
    return res;
}
