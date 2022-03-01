
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

void topView(Tnode *node)
{
    // base cases
    if (node == NULL)
        return;

    // a map to store the vertical line and data
    map<int, int> m;

    // queue to store the current line and the node
    queue<pair<Tnode *, int>> q;

    // push the root of tree to the queue
    q.push({node, 0});

    // cout << "Starting line " << endl;

    cout << "Top View of Tree" << endl;

    while (!q.empty())
    {
        auto it = q.front();
        // cout << it.first << " " << it.second << endl;
        q.pop();

        Tnode *curr = it.first; // current node
        int line = it.second;   // the current vertical line

        // cout << line << endl;

        if (m.find(line) == m.end())
            m[line] = curr->data;

        if (curr->left)
        {
            q.push({curr->left, line - 1});
        }

        if (curr->right)
        {
            q.push({curr->right, line + 1});
        }
    }

    // print the topView
    for (auto x : m)
    {
        // cout << "log" << endl;
        cout << x.second << " ";
    }
    cout << endl;
}

void bottomView(Tnode *node)
{
    // base cases
    if (node == NULL)
        return;

    // a map to store the vertical line and data
    map<int, int> m;

    // queue to store the current line and the node
    queue<pair<Tnode *, int>> q;

    // push the root of tree to the queue
    q.push({node, 0});

    // cout << "Starting line " << endl;
    cout << "Bottom View of Tree" << endl;

    while (!q.empty())
    {
        auto it = q.front();
        // cout << it.first << " " << it.second << endl;
        q.pop();

        Tnode *curr = it.first; // current node
        int line = it.second;   // the current vertical line

        // cout << line << endl;

        m[line] = curr->data;

        if (curr->left)
        {
            q.push({curr->left, line - 1});
        }

        if (curr->right)
        {
            q.push({curr->right, line + 1});
        }
    }

    // print the bottomView
    for (auto x : m)
    {
        // cout << "log" << endl;
        cout << x.second << " ";
    }
    cout << endl;
}

// self notes:
// 🚀 for every level, the first node (on the right side) will be our right side view
// 🚀 if the level of the tree == my vector's size, I need to push it into my vector
// 🚀 if at any point we reach a null node, we just need to return (base case)

void rightView(Tnode *node)
{
    // base cases
    if (node == NULL)
        return;

    queue<Tnode *> queue;
    queue.push(node);

    // During level order traversal, we had one size variable which tells the size of queue at each level so if i == size - 1;
    // then that element is the last element of that level so we can push it into the data structure.

    cout
        << "Right View of Tree" << endl;
    while (!queue.empty())
    {
        int size = queue.size();

        while (size--)
        {
            Tnode *node = queue.front();
            queue.pop();

            if (size == 0)
                cout << node->data << " ";

            if (node->left)
                queue.push(node->left);
            if (node->right)
                queue.push(node->right);
        }
    }
    cout << endl;
}

void leftView(Tnode *node)
{
    // base cases
    if (node == NULL)
        return;

    queue<Tnode *> queue;
    queue.push(node);

    // During level order traversal, we had one size variable which tells the size of queue at each level so if i == 0;
    // then that element is the last element of that level so we can push it into the data structure.

    cout << "Left View of Tree" << endl;

    while (!queue.empty())
    {
        int size = queue.size();

        for (int i = 0; i < size; i++)
        {
            Tnode *node = queue.front();
            queue.pop();

            if (i == 0)
                cout << node->data << " ";

            if (node->left)
                queue.push(node->left);
            if (node->right)
                queue.push(node->right);
        }
    }
    cout << endl;
}

// void NodesinLine(Tnode *node) // prints the nodes in a vertical line
// {
//     // base cases
//     if (node == NULL)
//         return;

//     // a map to store the vertical line and data
//     map<int, vector<int>> m;

//     // queue to store the current line and the node
//     queue<pair<Tnode *, int>> q;

//     // push the root of tree to the queue
//     q.push({node, 0});

//     int l;
//     cout << "Enter a vertical line number: " << endl;
//     cin >> l;

//     // cout << "Starting line " << endl;

//     cout << "Top View of Tree" << endl;

//     while (!q.empty())
//     {
//         auto it = q.front();
//         // cout << it.first << " " << it.second << endl;
//         q.pop();

//         Tnode *curr = it.first; // current node
//         int line = it.second;   // the current vertical line

//         // cout << line << endl;

//         if (m.find(line) == m.end())
//             m[line] = curr->data;

//         if (curr->left)
//         {
//             q.push({curr->left, line - 1});
//         }

//         if (curr->right)
//         {
//             q.push({curr->right, line + 1});
//         }
//     }

//     // print the topView
//     for (auto x : m)
//     {
//         // cout << "log" << endl;
//         cout << x.second << " ";
//     }
//     cout << endl;
// }

bool pathExists(Tnode *node, vector<int> &arr, int key)
{
    if (node == NULL)
        return false;

    // push node to the arr
    arr.push_back(node->data);

    if (node->data == key)
    {
        return true;
    }

    if (pathExists(node->left, arr, key) || pathExists(node->right, arr, key))
    {
        return true;
    }

    arr.pop_back();
    return false;
}

void printPath(Tnode *node, int key)
{
    vector<int> arr;

    if (pathExists(node, arr, key))
    {
        cout << "Path to " << key << ": ";
        for (auto x : arr)
        {
            if (x == arr[arr.size() - 1])
            {
                cout << x << endl;
                break;
            }
            cout << x << "->";
        }
    }
    else
        cout << "Path does not exist" << endl;
}

bool isTreeSymetrical(Tnode *node1, Tnode *node2)
{
    //     Self Notes:
    // 💡 Mirror property is    left == right and right == left
    // 💡 pre-order traversal on root->left subtree, (root, left, right)
    // 💡 modified pre-order traversal on root->right subtree, (root, right, left)
    // 💡 compare the node val's if they are the same
    // 💡 Do both traversals at the same time
    // 💡 if left is null or right is null, then both sides must match and return true (base case)

    if (!node1)
        return !node2;
    if (!node2)
        return !node1;
    return (node1->data == node2->data) && (isTreeSymetrical(node1->left, node2->right)) && (isTreeSymetrical(node1->right, node2->left));
}

Tnode *LCA(Tnode *node, int val1, int val2)
{
    // Brute force solution here is print the path for the two nodes and compare the paths.
    // return the last node, after which the paths become different.

    // assuming that val1 and val2 exist in the tree
    if (node == NULL || node->data == val1 || node->data == val2)
        return node;

    Tnode *left = LCA(node->left, val1, val2);
    Tnode *right = LCA(node->right, val1, val2);

    if (left && right)
        return node;
    
    return (left != NULL ? left : right);
}