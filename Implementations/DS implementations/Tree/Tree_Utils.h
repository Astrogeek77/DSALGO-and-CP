
// #define MAX = 1e7+10;
int MIN = INT_MIN;
int MAX = INT_MAX;

vector<int> result;

bool treeIncludes(Tnode *root, int key)
{
    if (root == NULL)
        return false;
    if (root->data == key)
        return true;

    queue<Tnode *> queue;
    queue.push(root);

    while (!queue.empty())
    {
        Tnode *current = queue.front();
        if (current->data == key)
            return true;

        if (current->left)
            queue.push(current->left);
        if (current->right)
            queue.push(current->right);

        queue.pop();
    }
    return false;
}

bool treeIncludesRecursive(Tnode *root, int key)
{
    if (root == NULL)
        return false;
    if (root->data == key)
        return true;

    return treeIncludes(root->left, key) || treeIncludes(root->right, key);
}

int treeSumRecursive(Tnode *root, int sum)
{
    if (root == NULL)
        return 0;
    sum += root->data + treeSumRecursive(root->left, sum) + treeSumRecursive(root->right, sum);
    return sum;
}

int treeSum(Tnode *root, int sum)
{
    // Breadth First Traversal
    if (root == NULL)
        return 0;

    queue<Tnode *> queue;
    queue.push(root);

    while (!queue.empty())
    {
        Tnode *current = queue.front();
        sum += current->data;

        if (current->left)
            queue.push(current->left);
        if (current->right)
            queue.push(current->right);

        queue.pop();
    }

    return sum;
}

int findMinRecursive(Tnode *root)
{
    if (root == NULL)
        return MAX;

    return min(findMinRecursive(root->left), min(findMinRecursive(root->right), root->data));
}

int findMaxRecursive(Tnode *root)
{
    if (root == NULL)
        return MIN;

    return max(findMaxRecursive(root->left), max(findMaxRecursive(root->right), root->data));
}

int findMin(Tnode *root)
{
    if (root == NULL)
        return MAX;

    queue<Tnode *> queue;
    int minvalue = root->data;
    queue.push(root);

    while (!queue.empty())
    {
        Tnode *current = queue.front();
        if (minvalue > current->data)
            minvalue = current->data;

        if (current->left)
            queue.push(current->left);
        if (current->right)
            queue.push(current->right);

        queue.pop();
    }
    return minvalue;
}

int maxRoottoLeafSum(Tnode *root)
{
    if (root == NULL)
        return MIN + 1000;
    if (root->left == NULL && root->right == NULL)
        return root->data;

    return max(maxRoottoLeafSum(root->left) + root->data, maxRoottoLeafSum(root->right) + root->data);
}

int minRoottoLeafSum(Tnode *root)
{
    if (root == NULL)
        return MAX - 1000;
    if (root->left == NULL && root->right == NULL)
        return root->data;

    return min(minRoottoLeafSum(root->left) + root->data, minRoottoLeafSum(root->right) + root->data);
}

// int maxRoottoLeaf(Tnode *root)
// {
//     if (root == NULL)
//         return MAX - 1000;
//     if (root->left == NULL && root->right == NULL)
//         return root->data;
    
//     stack<Tnode *> stack;
//     stack.push(root);

//     while(!stack.empty()){
        
//     }
// }

bool isSameTree(Tnode *node1, Tnode *node2)
{
    if (!node1)
        return !node2;
    if (!node2)
        return !node1;
    return (node1->data == node2->data) && (isSameTree(node1->left, node2->left)) && (isSameTree(node1->right, node2->right));
}

int maxPathSum(Tnode *node, int &maxi)
{
    if (node == NULL)
        return 0;
    int lh = max(0, maxPathSum(node->left, maxi));
    int rh = max(0, maxPathSum(node->right, maxi));
    maxi = max(maxi, lh + rh + node->data);
    return max(lh, rh) + node->data;
}

int maxDiameter(Tnode *node, int &d)
{
    if (node == NULL)
        return 0;
    int lh = maxDiameter(node->left, d);
    int rh = maxDiameter(node->right, d);
    d = max(d, lh + rh);
    return (1 + max(lh, rh));
}

int maxDepth(Tnode *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);

        if (leftDepth < rightDepth)
            return (leftDepth + 1);
        else
            return (rightDepth + 1);

        // cout << leftDepth << rightDepth << endl;
    }
    // return (max(leftDepth, rightDepth) + 1);
}

int calcHeight(Tnode *node)
{
    if (node == NULL)
        return 0;
    int lh = calcHeight(node->left);
    if (lh == -1)
        return -1;
    int rh = calcHeight(node->right);
    if (rh == -1)
        return -1;

    if (abs(lh - rh) > 1)
        return -1;
    return max(lh, rh) + 1;
}

bool isBalanced(Tnode *node)
{
    return (calcHeight(node) != -1);
}

int IterativeCalcHeight(Tnode *node)
{
    if (node == NULL)
        return 0;

    queue<Tnode *> queue;
    int height = 0;
    int nodeCount;
    Tnode *current;

    queue.push(node);
    while (!queue.empty())
    {
        nodeCount = queue.size();
        height++;

        while (nodeCount--)
        {
            current = queue.front();

            if (current->left != NULL)
                queue.push(current->left);
            if (current->right != NULL)
                queue.push(current->right);

            queue.pop();
        }
    }
    return height;
}