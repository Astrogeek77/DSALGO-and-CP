
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

int maxWidth(Tnode *node)
{
    /*
    func to calc max width of a tree dependent on a Level
    we do level order traversel and assign the value to a node (levelNum)
    acc to the rule l = 2 * i , r = 2 * i + 1 (i = parent, l, r = child)
    */
    if (node == NULL)
        return 0;
    queue<pair<Tnode *, int>> q;
    q.push({node, 0});
    int w = 0; // width

    while (!q.empty())
    {
        int size = q.size();
        int levelMin = q.front().second;
        int last, first;

        for (int i = 0; i < size; i++)
        {
            auto it = q.front();
            Tnode *curr = it.first; // current node
            q.pop();                // remove

            // we subtract minimum in level to start the next level from zero thus eliminating the overflow issue in case of skew trees.
            int id = it.second - levelMin;
            if (i == 0)
                first = id;
            if (i == size - 1)
                last = id;

            if (curr->left)
            {
                q.push({curr->left, (2 * id) + 1});
            }
            if (curr->right)
            {
                q.push({curr->right, (2 * id) + 2});
            }
        }
        w = max(w, last - first + 1);
    }
    return w;
}

void changeToSumTree(Tnode *node)
{
    /*
    covert a arbitrary tree to a tree that follows children sum property
    that is parent = left + right;
    */

    if (node == NULL)
        return;

    int child = 0;

    // calc the child sum value for a node
    if (node->left)
    {
        child += node->left->data;
    }
    if (node->right)
    {
        child += node->right->data;
    }

    // check if the child sum is greater or less than root value, update root or childs accordingly
    int d = node->data;
    if (child >= d)
    {
        node->data = child;
    }
    else
    {
        if (node->left)
            node->left->data = d;
        if (node->right)
            node->right->data = d;
    }

    // call for left and right child
    changeToSumTree(node->left);
    changeToSumTree(node->right);

    // again calc sum while going up towards the root to update it
    int total = 0;
    if (node->left)
        total += node->left->data;
    if (node->right)
        total += node->right->data;

    if (node->left or node->right) // should not be a leaf
        node->data = total;
}

void markParents(Tnode *node, unordered_map<Tnode *, Tnode *> &parentTrack)
{
    // function to create a map of nodes with their respective parents for traversal
    if (node == NULL)
        return;

    queue<Tnode *> queue;
    queue.push(node);

    while (queue.empty() == false)
    {
        Tnode *curr = queue.front();
        queue.pop();
        if (curr->left)
        {
            parentTrack[curr->left] = curr;
            queue.push(curr->left);
        }

        if (curr->right)
        {
            parentTrack[curr->right] = curr;
            queue.push(curr->right);
        }
    }
}

Tnode *searchNodeByValue(Tnode *node, int value)
{
    if (node == NULL || node->data == value)
        return node;

    queue<Tnode *> queue;
    queue.push(node);

    while (!queue.empty())
    {
        Tnode *curr = queue.front();
        if (curr->data == value)
            return curr;
        queue.pop();

        if (curr->left)
        {
            queue.push(curr->left);
        }

        if (curr->right)
        {
            queue.push(curr->right);
        }
    }
    return NULL;
}

// void printVector(vector<int> v)
// {
//     for (auto x : v)
//     {
//         cout << x << " ";
//     }
//     cout << endl;
// }

void NodesAtDistanceK(Tnode *node, int target, int k)
{
    // func to find all the nodes from a target node that lie at a given distance K.

    if (node == NULL)
        return;

    /*
        *Self Notes:
         Mark each node to its parent to traverse upwards
         We will do a BFS traversal starting from the target node
         As long as we have not seen our node previously, Traverse up, left, right until reached Kth distance
         when reached Kth distance, break out of BFS loop and remaining node's values in our queue is our result

         thus basically our approach is to convert the tree into a undirected graph of sorts.
    */
    unordered_map<Tnode *, Tnode *> parentTrack;
    markParents(node, parentTrack);

    unordered_map<Tnode *, bool> visited;

    queue<Tnode *> queue;
    // cout << "Start" << endl;
    Tnode *targetNode = searchNodeByValue(node, target);
    if (targetNode == NULL)
        return;

    // cout << "TargetNode" << targetNode->data << endl;

    queue.push(targetNode);
    visited[targetNode] = true;

    int dist = 0;

    while (!queue.empty())
    {
        // cout << "Distance" << dist << endl;
        int size = queue.size();
        if (dist++ == k) // break out of loop as soon as distance == k
            break;

        for (int i = 0; i < size; i++)
        {
            Tnode *curr = queue.front();
            queue.pop();

            if (curr->left and !visited[curr->left])
            {
                queue.push(curr->left); // push left if not visited
                visited[curr->left] = true;
            }

            if (curr->right and !visited[curr->right])
            {
                queue.push(curr->right); // push right if not visited
                visited[curr->right] = true;
            }

            if (parentTrack[curr] and !visited[parentTrack[curr]])
            {
                queue.push(parentTrack[curr]); // push parent if not visited
                visited[parentTrack[curr]] = true;
            }
        }
    }
    vector<int> result;

    while (queue.empty() == false)
    {
        Tnode *temp = queue.front();
        queue.pop();
        result.push_back(temp->data);
    }
    printVector(result);
}

int getBurnTime(Tnode *node, int target)
{
    /*
     *Func to calc burn time(in secs) for a tree, starting from the given node
     */

    if (node == NULL)
        return 0;

    unordered_map<Tnode *, Tnode *> parentTrack;
    markParents(node, parentTrack);

    unordered_map<Tnode *, bool> visited;

    queue<Tnode *> queue;
    // cout << "Start" << endl;
    Tnode *targetNode = searchNodeByValue(node, target);
    if (targetNode == NULL)
        return 0;

    // cout << "TargetNode" << targetNode->data << endl;

    queue.push(targetNode);
    visited[targetNode] = true;

    int time = 0;

    while (!queue.empty())
    {
        // cout << "Time" << time << endl;
        int size = queue.size();
        bool nodeExists = false;

        for (int i = 0; i < size; i++)
        {
            Tnode *curr = queue.front();
            queue.pop();

            if (curr->left and !visited[curr->left])
            {
                nodeExists = true;
                queue.push(curr->left); // push left if not visited
                visited[curr->left] = true;
            }

            if (curr->right and !visited[curr->right])
            {
                nodeExists = true;
                queue.push(curr->right); // push right if not visited
                visited[curr->right] = true;
            }

            if (parentTrack[curr] and !visited[parentTrack[curr]])
            {
                nodeExists = true;
                queue.push(parentTrack[curr]); // push parent if not visited
                visited[parentTrack[curr]] = true;
            }
        }
        if (nodeExists)
            time++;
    }
    return time;
}

int getLeftHeight(Tnode *node)
{
    int lh = 0;
    while (node != NULL)
    {
        lh++;
        node = node->left;
    }
    return lh;
}

int getRightHeight(Tnode *node)
{
    int rh = 0;
    while (node != NULL)
    {
        rh++;
        node = node->right;
    }
    return rh;
}

int countNodesCBT(Tnode *node)
{ //! O((log N) ^ 2)
    /*
     *func to calc total number of nodes in a complete binary tree
     *using relation that total nodes in full binary tree are 2 ^ h - 1 (h = height)
     */

    int lh = getLeftHeight(node);
    int rh = getRightHeight(node);

    if (lh == rh)
        return (1 << lh) - 1;

    return 1 + countNodesCBT(node->left) + countNodesCBT(node->right);
}

//* Build Tree from preorder and inorder

Tnode *constructTree1(vector<int> preorder, int preStart, int preEnd, vector<int> inorder, int inStart, int inEnd, map<int, int> &map)
{
    if (preStart > preEnd or inStart > inEnd)
    {
        return NULL;
    }

    Tnode *root = new Tnode(preorder[preStart]); // get root
    int inRoot = map[root->data];                // get position of root in inorder
    int numsLeft = inRoot - inStart;             // the count of nums on the left of inroot

    root->left = constructTree1(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, map);
    root->right = constructTree1(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, map);
    return root;
}

Tnode *buildTree1(vector<int> preorder, vector<int> inorder)
{
    //? preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
    map<int, int> map;
    for (int i = 0; i < inorder.size(); i++)
        map[inorder[i]] = i; // mapping the index of inorder

    Tnode *root = constructTree1(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, map);
    return root;
}

// *Build Tree from postorder and inorder

Tnode *constructTree2(vector<int> inorder, int inStart, int inEnd, vector<int> postorder, int postStart, int postEnd, map<int, int> &map)
{
    if (postStart > postEnd or inStart > inEnd)
    {
        return NULL;
    }

    Tnode *root = new Tnode(postorder[postEnd]); // get the root node
    int inRoot = map[root->data];                // get the position of root in the inorder
    int numsLeft = inRoot - inStart;             // the count of nums on the left of inroot

    root->left = constructTree2(inorder, inStart, inRoot - 1, postorder, postStart, postStart + numsLeft - 1, map);
    root->right = constructTree2(inorder, inRoot + 1, inEnd, postorder, postStart + numsLeft, postEnd - 1, map);
    return root;
}

Tnode *buildTree2(vector<int> inorder, vector<int> postorder)
{
    // Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
    // Output: [3,9,20,null,null,15,7]

    if (inorder.size() != postorder.size())
        return NULL;

    map<int, int> map;
    for (int i = 0; i < inorder.size(); i++)
        map[inorder[i]] = i; // mapping the index of inorder

    Tnode *root = constructTree2(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, map);
    return root;
}

string serialize(Tnode *node)
{
    if (!node)
        return "";

    string result = "";
    queue<Tnode *> queue;
    queue.push(node);

    while (!queue.empty())
    {
        auto curr = queue.front();
        queue.pop();

        if (curr == NULL)
            result.append("#,");
        else {
            result.append(to_string(curr->data) + ",");
            queue.push(curr->left);
            queue.push(curr->right);
        }
    }
    cout << "Serialized Tree: " << result << endl;
    return result;
}

Tnode *deserialize(string s){
    
}
