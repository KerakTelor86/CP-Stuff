////////////////////////////////
//        CP Template         //
//        (KerakTelor)        //
//      you cin you lose      //
////////////////////////////////

////////////////////////////////////////////
// /*online judge: time limit exceeded */ //
// /*cp nibbas:                        */ //
//   #pragma GCC optimize("Ofast")        //
//   #pragma GCC optimize("unroll-loops") //
////////////////////////////////////////////

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int inf=2e9;
const ll inf64=9e18;

#ifdef _WIN32
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
inline void print_int(T x,bool f=1)
{
    if(f&&x==0)
    {
        print_char('0');
        return;
    }
    else if(x==0)
        return;
    if(x<0)
    {
        print_char('-');
        x=-x;
    }
    print_int(x/10,0);
    print_char(x%10+'0');
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

inline void read_str(string &s,char delim='\n',bool skip_whtspc=0,int bufsize=8192)
{
    char t[bufsize];
    read_cstr(t,delim,skip_whtspc);
    s=t;
}

inline void print_str(string s)
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

ll powa(ll a,ll b,ll m=inf64)
{
    if(b==0)
        return a;
    if(b&1)
        return (a*powa(a,b-1,m))%m;
    ll x=powa(a,b>>1,m);
    return (x*x)%m;
}

ll gcd(ll a,ll b)
{
    return b==0?a:gcd(b,a%b);
}

ll lcm(ll a,ll b)
{
    return a*b/gcd(a,b);
}

template<typename T>
int fcmp(T a,T b,T eps)
{
    T t=a-b,abst=abs(t);
    if(abst<eps)
        return 0;
    if(t>-eps)
        return 1;
    return -1;
}

int main()
{
    return 0;
}
