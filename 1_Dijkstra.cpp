#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int, int>> st;
        vector<int> dist(V, 1e9);
        st.insert({0, S});
        dist[S] = 0;

        while (!st.empty())
        {
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);

            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int edgW = it[1];

                if (dis + edgW < dist[adjNode])
                {
                    if (dist[adjNode] != 1e9)
                        st.erase({dist[adjNode], adjNode});
                    dist[adjNode] = dis + edgW;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};

int main()
{
    int V, E, S;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    cout << "Enter source vertex: ";
    cin >> S;

    vector<vector<int>> adj[V];

    cout << "Enter the edges (format: u v w where u -> v with weight w):\n";
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); 
    }

    Solution obj;
    vector<int> res = obj.dijkstra(V, adj, S);

    cout << "Shortest distances from source " << S << ":\n";
    for (int i = 0; i < V; i++)
    {
        if (res[i] == 1e9)
            cout << "INF ";
        else
            cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}

