#include <bits/stdc++.h>

struct Node
{
    Node *links[26];
    int cntEndsWith = 0;
    int cntPrefix = 0;

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
        // Write your code here.
        root = new Node();
    }

    void insert(string &word)
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
        node->incEnd();
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
