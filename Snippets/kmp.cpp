vec<int> prefix(string &s)
{
    int n=s.length();
    vec<int> x(n);
    for(int i=1;i<n;++i)
    {
        int j=x[i-1];
        while(j>0&&s[i]!=s[j])
            j=x[j-1];
        if(s[i]==s[j])
            ++j;
        x[i]=j;
    }
    return x;
}

vec<int> kmp(string &s,string &t)
{
    vec<int> res;
    auto p=prefix(t);
    int n=s.length(),m=t.length(),j=0;
    for(int i=0;i<n;++i)
    {
        if(s[i]==t[j])
        {
            ++j;
            if(j==m)
            {
                res.push_back(i-m+2);
                j=p[j-1];
            }
        }
        else
        {
            while(j>0&&s[i]!=t[j])
                j=p[j-1];
            if(s[i]==t[j])
                ++j;
        }
    }
    return res;
}

