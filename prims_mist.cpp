#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>
const int N = 1e5 + 5;
vector<pi> V[N];
bool vis[N];

class Edge
{
public:
    int u, v, w;

    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

class cmp
{
public:
    bool operator()(Edge a, Edge b)
    {
        return a.w > b.w;
    }
};

void prims_mist(int s)
{

    priority_queue<Edge, vector<Edge>, cmp> pq;

    pq.push(Edge(s, s, 0));

    vector<Edge> ed;

    while (!pq.empty())
    {
        Edge parent = pq.top();
        pq.pop();

        int u = parent.u;
        int v = parent.v;
        int w = parent.w;

        if (vis[v])
            continue;
        vis[v] = true;

        ed.push_back(parent);

        for (pi i : V[v])
        {
            if (!vis[i.first])
            {
                pq.push(Edge(v, i.first, i.second));
            }
        }
    }
    ed.erase(ed.begin());
    cout << endl
         << endl;
    for (Edge i : ed)
    {
        cout << i.u << " " << i.v << " " << i.w << endl;
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        V[u].push_back({v, w});
        V[v].push_back({u, w});
    }

    prims_mist(1);

    return 0;
}