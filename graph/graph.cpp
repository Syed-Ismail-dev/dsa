#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;
// class node{
//     int data;
//     node* next;
// };

class graph
{
private:
    list<int> *l;
    int v;

public:
    graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }
    void addedge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void bfs()
    {
        queue<int> q;
        vector<int> vec(v, false);
        q.push(0);
        vec[0] = true;
        while (q.size() > 0)
        {
            int u = q.front();
            q.pop();
            cout << u << " ";
            for (int n : l[u])
            {
                if (!vec[n])
                {
                    vec[n] = true;
                    q.push(n);
                }
            }
        }
    }

    void dfsc(int src, vector<bool> &vis)
    {
        cout << src << " ";
        vis[src] = true;
        for (int n : l[src])
        {
            if (!vis[n])
            {
                dfsc(n, vis);
            }
        }
    }

    void dfs()
    {
        int src = 0;
        vector<bool> vis(v, false);
        dfsc(src, vis);
    }
    bool dfscirclehelper(int u, vector<bool> &vis, int par)
    {
        vis[u] = true;
        list<int> neigh = l[u];
        for (int n : neigh)
        {
            if (!vis[u])
            {
                par = u;
                if (dfscirclehelper(n, vis, par))
                {
                    return true;
                }
            }
            else if (par != n)
            {
                return true;
            }
        }
        return false;
    }
    bool dfsiscircle()
    {
        int src = 0;
        int par = -1;
        vector<bool> vis(v, false);

        return dfscirclehelper(src, vis, par);
    }
    bool bfscircle(int start)
    {
        queue<pair<int,int>> q;
        vector<bool> vis(v, false);
        q.push({start,-1});
        vis[start] = true;
        while (!q.empty())
        {
            int cur = q.front().first;
            int par = q.front().second;
            q.pop();

            for (int n : l[cur])
            {
                if (!vis[cur])
                {
                    vis[n] = true;
                    q.push({n,cur});
                   
                }
                else if (n != par)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    graph test(7);
    test.addedge(0, 1);
    test.addedge(2, 3);
    test.addedge(3, 4);
    test.addedge(4, 5);
    test.addedge(4, 6);
    test.addedge(5, 6);

    // test.bfs();
    // cout<<endl;
    // test.dfs();
    cout << endl;
    cout << test.dfsiscircle() << endl;
    cout << test.bfscircle(0) << endl;
    return 0;
}