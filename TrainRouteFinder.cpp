#include <bits/stdc++.h>
using namespace std;
class Route
{
public:
    int CheapestPath(int n, vector<vector<int>> &buses, int src, int dst, int k)
    {
        vector<pair<int, int>> adj[n];
        for (auto x : buses)
        {
            adj[x[0]].push_back({x[1], x[2]});
        }
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        vector<int> d(n, 1e9);
        d[src] = 0;
        while (!q.empty())
        {
            auto u = q.front();
            q.pop();
            int k1 = u.first;
            int s = u.second.first;
            int c = u.second.second;
            if (k1 > k)
            {
                continue;
            }
            for (auto x : adj[s])
            {
                int a = x.first;
                int b = x.second;
                if (c + b < d[a] && k1 <= k)
                {
                    d[a] = c + b;
                    q.push({1 + k1, {a, (c + b)}});
                }
            }
        }
        if (d[dst] == 1e9)
            return -1;
        return d[dst];
    }
};
int main()
{
    int tc = 1;
    while (tc--)
    {
        int n;
        cout << "Enter the Number of Areas" << endl;
        cin >> n;
        int edge;
        cout << "Enter the Number of Path" << endl;
        cin >> edge;
        vector<vector<int>> buses;
        cout << "Enter start point to end point and price in terms of Integer" << endl;
        for (int i = 0; i < edge; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            buses.push_back(temp);
        }

        int src, dst, k;
        cout << "Enter your journey starting and destination and stops" << endl;
        cin >> src >> dst >> k;
        Route r;
        cout << r.CheapestPath(n, buses, src, dst, k) << "\n";
    }
    return 0;
}
// } Driver Code Ends