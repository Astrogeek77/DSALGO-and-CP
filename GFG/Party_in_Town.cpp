class Solution
{
public:
    int maxd = 0;
    void dfs(int ind, vector<vector<int>> &adj, vector<int> &vis, int d)
    {
        // d -> depth / distance of each house from house(i)
        vis[ind] = 1;
        maxd = max(maxd, d); // max depth to which a node goes
        for (int i : adj[ind])
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, d + 1);
            }
        }
    }

    int partyHouse(int N, vector<vector<int>> &adj)
    {

        int ans = INT_MAX;
        // int house = -1;

        for (int i = 1; i <= N; i++)
        {
            vector<int> vis(N + 1, 0);
            maxd = 0;
            dfs(i, adj, vis, 0); // for each find maxdeptht to which it goes and finally find min of it

            ans = min(ans, maxd);
        }
        return ans;
    }
};