#include <bits/stdc++.h>
using namespace std;
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

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

int parent[1000];
int parentSize[1000];
void dsu_set(int n)
{
    for (int i = 0; i <= n; i++)
    {
        parent[i] = -1;
        parentSize[i] = 1;
    }
}

int dsu_find(int n)
{
    while (parent[n] != -1)
    {
        n = parent[n];
    }
    return n;
}

void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB)
    {
        if (parentSize[leaderA] > parentSize[leaderB])
        {
            // A leader
            parent[leaderB] = leaderA;
            parentSize[leaderA] += parentSize[leaderB];
        }
        else
        {
            parent[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> V;
    vector<Edge> ans;

    dsu_set(n);

    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        V.push_back(Edge(u, v, w));
    }
    sort(V.begin(), V.end(), cmp);

    for (Edge i : V)
    {
        // cout << i.u << " " << i.v << " " << i.w << endl;
        int u = i.u;
        int v = i.v;
        int w = i.w;

        int leaderA = dsu_find(u);
        int leaderB = dsu_find(v);

        if (leaderA == leaderB)
            continue;

        ans.push_back(i);
        dsu_union(u, v);
    }
    cout << endl
         << endl;
    for (Edge i : ans)
    {
        cout << i.u << " " << i.v << " " << i.w << endl;
    }

    return 0;
}