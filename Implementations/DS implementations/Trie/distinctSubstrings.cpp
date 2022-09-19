struct Node
{
    Node *links[26];
    bool flag = false;

    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void add(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    void setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
    }
};

int countDistinctSubstrings(string &s)
{
    Node *root = new Node();
    int count = 0;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        Node *node = root;
        for (int j = i; j < n; j++)
        {
            if (!node->containsKey(s[j]))
            {
                count++;
                node->add(s[j], new Node());
            }
            node = node->get(s[j]);
        }
    }
    return count + 1;
}