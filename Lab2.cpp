#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V, 1e8);
        dist[S] = 0;

        for (int i = 0; i < V - 1; i++) {
            for (auto &it : edges) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];

                if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                return {-1};
            }
        }

        return dist;
    }
};

int main() {
    int V, E, S;
    cin >> V >> E >> S;

    vector<vector<int>> edges(E, vector<int>(3));

    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    Solution obj;
    vector<int> dist = obj.bellman_ford(V, edges, S);

    for (int d : dist) {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}
