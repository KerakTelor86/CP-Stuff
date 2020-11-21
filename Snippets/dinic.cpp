using ll = long long;

const ll INF = 1e18;

class Dinic
{
private:
    struct Edge         // set the following:
    {                   // v = destination
        int v;          // cap = edge value
        ll cap, flow;   // flow = 0

        Edge(int _v, ll _cap) : v(_v), cap(_cap), flow(0) {}
    };

    int n;
    vector<vector<int>> gr;
    vector<Edge> e;
    vector<int> idx, lv;

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
                ll add = get_flow(
                    e[i].v,
                    t,
                    min(left, e[i].cap - e[i].flow)
                );
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

public:
    Dinic(int vertices) : n(vertices), gr(n) {}

    void add_edge(int from, int to, ll cap, bool directed = 1)
    {
        gr[from].push_back(e.size());
        e.emplace_back(to, cap);
        gr[to].push_back(e.size());
        e.emplace_back(from, directed ? 0 : cap);
    }

    ll get_max_flow(int s, int t)
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
};

