#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int flp=1e-6;
const int dflp=1e-12;
const int inf=2e9;
const int minf=-2e9;
const ll inf64=9e18;
const ll minf64=-9e18;

#ifdef WIN32
inline int getchar_unlocked()
{
    return _getchar_nolock();
}
inline void putchar_unlocked(char c)
{
    _putchar_nolock(c);
}
#endif

inline int raw_char()
{
    return getchar_unlocked();
}

inline int read_char()
{
    char c;
    do
    {
        c=getchar_unlocked();
    } while(c<33);
    return c;
}

inline void print_char(char c)
{
    putchar_unlocked(c);
}

template<typename T=ll>
inline T read_int()
{
    T temp=0;
    bool neg=0;
    char c=read_char();
    if(c=='-')
    {
        neg=1;
        c=raw_char();
    }
    while(c>='0'&&c<='9')
    {
        temp=temp*10+c-'0';
        c=raw_char();
    }
    return neg?-temp:temp;
}

template<typename T=ll>
inline void print_int(T x)
{
    if(x==0)
    {
        print_char('0');
        return;
    }
    char buff[24];
    int idx=0;
    if(x<0)
    {
        print_char('-');
        x=-x;
    }
    while(x)
    {
        buff[idx++]=x%10+'0';
        x/=10;
    }
    while(idx)
        print_char(buff[--idx]);
}

inline void read_str(std::string &s,char delim='\n',bool skip_whtspc=0,int bufsize=8192)
{
    char t[bufsize],c;
    if(skip_whtspc)
        c=read_char();
    else
        c=raw_char();
    int idx=0;
    while(c!=delim)
    {
        t[idx++]=c;
        c=raw_char();
    }
    t[idx]=0;
    raw_char();
    s=t;
}

inline void read_cstr(char *s,char delim='\n',bool skip_whtspc=0)
{
    char c;
    if(skip_whtspc)
        c=read_char();
    else
        c=raw_char();
    int idx=0;
    while(c!=delim)
    {
        s[idx++]=c;
        c=raw_char();
    }
    s[idx]=0;
    raw_char();
}

inline void print_str(std::string s)
{
    int len=s.length();
    for(int i=0;i<len;++i)
        print_char(i);
}

inline void print_cstr(const char *s)
{
    while(*s)
        print_char(*s++);
}

ll pow(int a,int b,ll m=inf64)
{
    ll ret=1;
    while(b)
        if(b&1)
        {
            ret*=a;
            --b;
        }
        else
        {
            b>>=1;
            ret*=ret;
        }
    return ret;
}

ll gcd(ll a,ll b)
{
    while(b)
    {
        ll t=a;
        a=b;
        b=a%b;
    }
    return a;
}

ll lcm(ll a,ll b)
{
    ll t=gcd(a,b);
    return a/t*b/t;
}

template<typename T>
int fcmp(T a,T b,T eps)
{
    T t=a-b,abst=t<0?-t:t;
    if(abst<=eps)
        return 0;
    if(t>=-eps)
        return 1;
    return -1;
}

int main()
{
    return 0;
}
