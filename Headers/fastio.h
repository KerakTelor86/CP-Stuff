#ifndef FASTIO_H_INCLUDED
#define FASTIO_H_INCLUDED

#include <cstdio>

#ifdef WIN32 //so it doesn't explode when run on a windows machine
inline int getchar_unlocked()
{
    return _getchar_nolock();
}

inline void putchar_unlocked(char c)
{
    _putchar_nolock(c);
}
#endif

inline int raw_char() //just an alias
{
    return getchar_unlocked();
}

inline int read_char() //ditto, but this one skips spaces, newlines, and other stuff
{
    char c;
    do
    {
        c=getchar_unlocked();
    } while(c<33); //skips ascii 0-32 (what we don't want)
    return c;
}

inline void print_char(char c) //just an alias
{
    putchar_unlocked(c);
}

template<typename T=long long> //you can read_int<whatever> if you want
inline T read_int()
{
    T temp=0;
    bool neg=0;
    char c=read_char();
    if(c=='-') //checks for negative sign
    {
        neg=1; //yee
        c=raw_char(); //moves to the next char
    }
    while(c>='0'&&c<='9') //uhh
    {
        temp=temp*10+c-'0'; //apparently doing this is faster than scanf
        c=raw_char(); //next char
    }
    return neg?-temp:temp; //owo?uwu:qwq;
}
//
//template<typename T=long long> //asdf see line 37
//inline void print_int(T x)
//{
//    if(x==0) //so it doesn't print an empty string if x is 0
//    {
//        print_char('0');
//        return;
//    }
//    char buff[24]; //char buffer
//    int idx=0; //index thingy
//    if(x<0) //if x is negative
//    {
//        print_char('-'); //prints -
//        x=-x; //turns x into a positive integer for easier handling down below
//    }
//    while(x) //while x!=0
//    {
//        buff[idx++]=x%10+'0'; //yee
//        x/=10; //yee
//    }
//    while(idx)
//        print_char(buff[--idx]); //prints buffer starting from behind
//}

template<typename T=long long> //asdf see line 37
inline void print_int(T x,bool first=1) //better than the commented out one, no need for buffers
{
    if(first&&x==0) //so it doesn't print an empty string if x is 0
    {
        print_char('0');
        return;
    }
    else if(x==0) //stops when x is 0
        return;
    if(x<0)
    {
        print_char('-');
        x=-x;
    }
    print_int(x/10,0); //uses recursion to print from behind
    print_char(x%10+'0');
}

inline void read_str(std::string &s,char delim='\n',bool skip_whtspc=0,int bufsize=8192)
{
    char t[bufsize],c;
    if(skip_whtspc) //uses read_char() to skip whitespaces if needed
        c=read_char();
    else
        c=raw_char();
    int idx=0;
    while(c!=delim) //while !=delim gets each char in the input stream
    {
        t[idx++]=c;
        c=raw_char();
    }
    t[idx]=0; //null behind t (c string)
    raw_char(); //throws away the delim char
    s=t; //initializes s to t
}

inline void read_cstr(char *s,char delim='\n',bool skip_whtspc=0) //read_str but c string
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
        print_char(i); //one by one
}

inline void print_cstr(const char *s)
{
    while(*s) //while(*s!='\0')
        print_char(*s++);
}

#endif // FASTIO_H_INCLUDED
