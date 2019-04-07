#include <iostream>

template<typename T>
int fcmp(T a,T b,T eps)
{
    T t=a-b,abst=t<0?-t:t;
    if(abst<=eps) //if a == b
        return 0;
    if(t>=-eps) //if a > b
        return 1;
    return -1; //if a < b
}

int main()
{
    double a=0.3,b=0.4;
    printf("%d\n",fcmp(a,b,1e-12));
}
