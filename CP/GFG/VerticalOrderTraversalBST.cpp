vector<int> vertical_order_traversal(node *root)
{

    vector<int> ans;
    if (root == NULL)
        return ans;

    map<int, map<int, vector<int>>> m;     // mapping of horizontal distance to levelwise nodes where levelwise nodes are itself a mapping of int level and vector<int> where ans is stored.
    queue<pair<node *, pair<int, int>>> q; // first int representing horizontal distance and second int representing level;
    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty())
    {
        pair<node *, pair<int, int>> temp = q.front();
        q.pop();

        node *front_node = temp.first;
        int hd = temp.second.first;
        int level = temp.second.second;
        m[hd][level].push_back(front_node->data);

        if (front_node->left)
            q.push(make_pair(front_node->left, make_pair(hd - 1, level + 1)));

        if (front_node->right)
            q.push(make_pair(front_node->right, make_pair(hd + 1, level + 1)));
    }

    for (auto i : m)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }

    return ans;
}