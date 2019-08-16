string halve(string s)
{
    const int l=s.length();
    string t(l,0);
    for(int i=0;i<l;++i)
        t[i]=s[i]>>1;
    for(int i=0;i<l-1;++i)
        if(s[i]&1)
            t[i+1]+=5;
    int i;
    for(i=0;i<l&&!t[i];++i);
    return t.substr(i);
}
