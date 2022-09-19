struct Node
{
    Node *links[26];
    bool flag = false;
    int cntEndsWith = 0;
    int cntPrefix = 0;

    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    void add(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
    }

    int getEnd() { return cntEndsWith; }
    int getPrefix() { return cntPrefix; }

    void incEnd() { cntEndsWith++; }
    void incPre() { cntPrefix++; }
    void delEnd() { cntEndsWith--; }
    void delPre() { cntPrefix--; }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!(node->containsKey(word[i])))
            {
                node->add(word[i], new Node());
            }

            node = node->get(word[i]);
            node->incPre();
        }

        node->setEnd();
        node->incEnd();
    }

    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!(node->containsKey(word[i])))
            {
                return false;
            }

            node = node->get(word[i]);
        }

        return node->isEnd();
    }

    bool startsWith(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!(node->containsKey(word[i])))
            {
                return false;
            }

            node = node->get(word[i]);
        }

        return true;
    }

    int countWordsEqualTo(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
                return 0;
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
                return 0;
        }
        return node->getPrefix();
    }

    void erase(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
                node->delPre();
            }
            else
                return;
        }
        node->delEnd();
    }
};

/**
 *Your Trie object will be instantiated and called as such:
 *Trie* obj = new Trie();
 *obj->insert(word);
 *bool param_2 = obj->search(word);
 *bool param_3 = obj->startsWith(prefix);
 */