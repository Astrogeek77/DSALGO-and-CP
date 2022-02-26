#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Tnode
{
public:
    int data;
    Tnode *left;
    Tnode *right;
    Tnode(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};