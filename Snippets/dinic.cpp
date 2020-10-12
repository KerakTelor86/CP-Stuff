#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

using ll = long long;
using ld = long double;

template<class T>
using vec = vector<T>;
template<class T>
using v2d = vector<vector<T>>;
template<class T>
using prq = priority_queue<T>;
template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

struct Edge
{
    int v;
    ll cap, flow;
};

const ll INF = 1e18;

int n, m;
v2d<int> gr;
vec<Edge> e;
vec<int> idx, lv;

bool has_path(int s, int t)
{
    queue<int> q;
    q.push(s);
    lv.assign(n, -1);
    lv[s] = 0;
    while(!q.empty())
    {
        int c = q.front();
        q.pop();
        if(c == t)
        {
            break;
        }
        for(auto& i : gr[c])
        {
            if(lv[e[i].v] == -1 && e[i].cap > e[i].flow)
            {
                lv[e[i].v] = lv[c] + 1;
                q.push(e[i].v);
            }
        }
    }
    return lv[t] != -1;
}

ll get_flow(int s, int t, ll left)
{
    if(!left || s == t)
    {
        return left;
    }
    while(idx[s] < (int) gr[s].size())
    {
        int i = gr[s][idx[s]];
        if(lv[e[i].v] == lv[s] + 1)
        {
            ll add = get_flow(e[i].v, t, min(left, e[i].cap - e[i].flow));
            if(add)
            {
                e[i].flow += add;
                e[i ^ 1].flow -= add;
                return add;
            }
        }
        ++idx[s];
    }
    return 0;
}

ll dinic(int s, int t)
{
    ll res = 0;
    while(has_path(s, t))
    {
        idx.assign(n, 0);
        while(ll add = get_flow(s, t, INF))
        {
            res += add;
        }
    }
    return res;
}

int main()
{
    scanf("%d %d", &n, &m);
    gr.assign(n, {});
    e.reserve(m);
    vec<map<int, ll>> temp(n);
    for(int i = 0; i < m; ++i)
    {
        int u, v;
        ll w;
        scanf("%d %d %lld", &u, &v, &w);
        if(u == v)
        {
            continue;
        }
        --u, --v;
        if(u > v)
        {
            swap(u, v);
        }
        temp[u][v] += w;
    }
    for(int i = 0; i < n; ++i)
    {
        for(auto& j : temp[i])
        {
            gr[i].push_back(e.size());
            e.push_back({j.fi, j.se, 0});
            gr[j.fi].push_back(e.size());
            e.push_back({i, j.se, 0});
        }
    }
    printf("%lld\n", dinic(0, n - 1));
}

