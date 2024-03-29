void printPreorder(Tnode *node)
{
    // root left right
    if (node == NULL)
        return;

    cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

void printInorder(Tnode *node)
{
    // left root right
    if (node == NULL)
        return;

    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

void printPostorder(Tnode *node)
{
    // left right root
    if (node == NULL)
        return;

    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}

void printLevelorder(Tnode *node)
{
    // level by level
    // Breadth First Search
    if (node == NULL)
        return;

    queue<Tnode *> queue;
    queue.push(node);
    Tnode *temp;

    while (queue.empty() == false)
    {
        temp = queue.front();
        cout << temp->data << " ";

        if (temp->left != NULL)
            queue.push(temp->left);
        if (temp->right != NULL)
            queue.push(temp->right);
        queue.pop();
    }
    cout << endl;
}

bool printGivenLevel(Tnode *node, int level)
{
    if (node == NULL)
    {
        return false;
    }

    if (level == 1)
    {
        cout << node->data << " ";
        return true;
    }

    bool left = printGivenLevel(node->left, level - 1);
    bool right = printGivenLevel(node->right, level - 1);

    return left || right;
}

void printLevelOrderTraversal(Tnode *node)
{
    int level = 1;
    while (printGivenLevel(node, level))
    {
        level++;
    }
}

void printVector(vector<int> &v)
{
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

void print2dVector(vector<vector<int>> &V)
{
    for(auto v : V)
    {
        printVector(v);
    }
    cout << endl;
}

// print level order traversal (iteratively)
vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector < int>> answer;
    if (!root) return answer;
    queue<TreeNode*> q;	
    q.push(root);	
    while (!q.empty())	
    {
        int size = q.size(); //storing queue size for inside loop
        vector<int> row;	// nodes in a level
        while (size--)
        {
            TreeNode *curr = q.front();
            q.pop();

            row.push_back(curr->val);	

            if (curr->left) q.push(curr->left);	
            if (curr->right) q.push(curr->right);	
        }
        answer.push_back(row);	
    }
    print2dVector(answer);
    return answer;
}

// print level order traversal (recursively)
vector<vector<int>> ans;
void helper(TreeNode* node, int level = 0)
{
    if(node == nullptr) return;
    if(level == ans.size()) ans.push_back(vector<int> ());
    
    ans[level].push_back(node->val);
    
    helper(node->left, level + 1);
    helper(node->right, level + 1);
}
vector<vector<int>> levelOrder(TreeNode *root)
{
    helper(root);
    print2dVector(ans);
    return ans;
}

// Level order traversal from bottom-up (Iteratively)
vector<vector<int>> levelOrderBottom(TreeNode *root)
{
    vector<vector < int>> answer;
    if (!root) return answer;
    queue<TreeNode*> q;	
    q.push(root);	
    while (!q.empty())	
    {
        int size = q.size(); //storing queue size for inside loop
        vector<int> row;	// nodes in a level
        while (size--)
        {
            TreeNode *curr = q.front();
            q.pop();

            row.push_back(curr->val);	

            if (curr->left) q.push(curr->left);	
            if (curr->right) q.push(curr->right);	
        }
        answer.push_back(row);	
    }
    reverse(answer.begin(), answer.end());
    print2dVector(answer);
    return answer;
}

// print level order Bottom-Up traversal (recursively)
vector<vector<int>> ans;
void helper(TreeNode* node, int level = 0)
{
    if(node == nullptr) return;
    if(level == ans.size()) ans.push_back(vector<int> ());

    ans[level].push_back(node->val);

    helper(node->left, level + 1);
    helper(node->right, level + 1);
}
vector<vector<int>> levelOrderBottom(TreeNode *root)
{
    helper(root);
    reverse(ans.begin(), ans.end());
    print2dVector(ans);
    return ans;
}

// Iterative DFS Traversals

void iterativePreorder(Tnode *node)
{
    // root left right

    // we traverse through and simultaneously print the node we push to stack,
    // we push right before left so that left comes out first

    if (node == NULL)
        return;

    stack<Tnode *> stack;
    stack.push(node);

    while (stack.empty() == false)
    {
        Tnode *temp = stack.top();
        cout << temp->data << ", ";
        stack.pop();

        // right is pushed first so that left is processed first
        if (temp->right)
            stack.push(temp->right);
        if (temp->left)
            stack.push(temp->left);
    }
}

void iterativeInorder(Tnode *node)
{
    // left root right

    // we traverse through left until node->left becomes null and then print the last node,
    //  its parent and move to its right

    if (node == NULL)
        return;

    stack<Tnode *> stack;
    Tnode *current = node;

    while (current != NULL || stack.empty() == false)
    {
        while (current != NULL)
        {
            stack.push(current);
            current = current->left;
        }

        current = stack.top();
        cout << current->data << " ";
        stack.pop();

        current = current->right;
    }
}

void IterativePostorder(Tnode *node)
{
    // left right root
    // using 2 stacks

    // we traverse using two stacks here we push the root to stack1 and then its left and right children and
    // pop the stack1 top and push it to stack 2, continuing this process we get a post order traversal when pop
    // elements in LIFO fashion from stack2

    if (node == NULL)
        return;

    stack<Tnode *> stack1;
    stack<Tnode *> stack2;

    Tnode *temp;

    stack1.push(node);

    while (!stack1.empty())
    {
        temp = stack1.top();
        stack1.pop();
        stack2.push(temp);

        if (temp->left != NULL)
            stack1.push(temp->left);
        if (temp->right != NULL)
            stack1.push(temp->right);
    }

    while (!stack2.empty())
    {
        temp = stack2.top();
        stack2.pop();
        cout << temp->data << " ";
    }
}

void IterativePostorder2(Tnode *node)
{
    // left right root
    // using 1 stack only

    // we traverse throught the nodes and go as left as posible then look for right child
    // next we reapeat the above step on the right child
    // once right child of a node is null we print node and check if its parents and print them
    // continuing these steps we get the post order traversal

    if (node == NULL)
        return;

    stack<Tnode *> st;
    // st.push(node);

    Tnode *current = node;

    while (!st.empty() || current != NULL)
    {
        if (current != NULL)
        {
            st.push(current);
            current = current->left;
        }
        else
        {
            Tnode *temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                cout << temp->data << " ";
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    cout << temp->data << " ";
                }
            }
            else
                current = temp;
        }
    }
}

void printVector(vector<int> v)
{
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

void allTraversals(Tnode *node)
{
    // three vectors storing the respective pre post and in order traversals
    vector<int> pre, in, post;

    // base case
    if (node == NULL)
        return;

    // we push to stack node along with a number which signifies which vector to push into
    stack<pair<Tnode *, int>> st;
    st.push({node, 1});

    // while stack is not empty do this
    while (!st.empty())
    {
        auto it = st.top();
        st.pop();
        // case 1 : num == 1 := push to preorder, increment the num and insert left child if exists
        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->left != NULL)
                st.push({it.first->left, 1});
        }
        // case 2: num == 2 := push to inorder, increment the num and insert right child if exists
        else if (it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->right != NULL)
                st.push({it.first->right, 1});
        }
        //  case 3: num == 3 := just push to postorder only
        else
        {
            post.push_back(it.first->data);
        }
    }
    // printing the three vectors
    cout << "Preorder Traversal" << endl;
    printVector(pre);
    cout << "Inorder Traversal" << endl;
    printVector(in);
    cout << "Postorder Traversal" << endl;
    printVector(post);
}

void BFT(Tnode *root)
{
    // level by level
    if (root == NULL)
        return;

    queue<Tnode *> queue;
    queue.push(root);

    while (!queue.empty())
    {
        Tnode *current = queue.front();
        cout << current->data << ", ";

        if (current->left)
            queue.push(current->left);
        if (current->right)
            queue.push(current->right);

        queue.pop();
    }
}

void DFTRecursive(Tnode *root)
{
    // root left right
    if (root == NULL)
        return;

    cout << root->data << ", ";
    DFTRecursive(root->left);
    DFTRecursive(root->right);
}

void DFT(Tnode *root)
{
    // root left right
    // Preorder Traversal

    if (root == NULL)
        return;

    stack<Tnode *> stack;
    stack.push(root);

    while (stack.empty() == false)
    {
        Tnode *current = stack.top();
        // result.push_back(current->data);
        cout << current->data << ", ";
        stack.pop();

        if (current->right)
            stack.push(current->right);
        if (current->left)
            stack.push(current->left);
    }
}

void zigzagTraversal(Tnode *node)
{
    // check base cases
    if (node == NULL)
        return;

    // use a queue for traversing the tree(basically level order)
    deque<Tnode *> queue;
    // push root to queue
    queue.push_back(node);

    // vector to store the traversal
    vector<int> v;

    v.push_back(node->data);

    Tnode *current;
    int l = 1;

    // until queue is not empty do this
    while (!queue.empty())
    {
        // tells how many elements are there in a level
        int size = queue.size();
        // cout << "Size :" << size << endl;

        for (int i = 0; i < size; i++) // runs for all elements in the level
        {
            // logic to reverse the order after every level
            if (l % 2 == 0)
            {
                current = queue.back();
                queue.pop_back();
            }
            else
            {
                current = queue.front();
                queue.pop_front();
            }

            if (l % 2 != 0)
            {
                if (current->right)
                {
                    queue.push_back(current->right);
                    v.push_back(current->right->data);
                }
                if (current->left)
                {
                    queue.push_back(current->left);
                    v.push_back(current->left->data);
                }
            }
            else
            {
                if (current->left)
                {
                    queue.push_front(current->left);
                    v.push_back(current->left->data);
                }
                if (current->right)
                {
                    queue.push_front(current->right);
                    v.push_back(current->right->data);
                }
            }
        }
        l++;
    }

    cout << "Zig Zag Traversal:" << endl;
    printVector(v);
}

bool checkLeaf(Tnode *node)
{
    return (!(node->left) && !(node->right));
}

void printLeftBoundary(Tnode *node)
{
    if (node == NULL)
        return;
    if (node->left)
    {
        // printing first to get top to down print
        cout << node->data << " ";
        printLeftBoundary(node->left);
    }
    else if (node->right)
    {
        cout << node->data << " ";
        printLeftBoundary(node->left);
    }
}

void printLeaves(Tnode *node)
{
    if (node == NULL)
        return;
    printLeaves(node->left);
    if (checkLeaf(node))
        cout << node->data << " ";
    printLeaves(node->right);
}

void printRightBoundary(Tnode *node)
{
    if (node == NULL)
        return;
    if (node->right)
    {
        // printing second to get bottom to up print
        printRightBoundary(node->right);
        cout << node->data << " ";
    }
    else if (node->left)
    {
        printRightBoundary(node->left);
        cout << node->data << " ";
    }
}

void boundaryTraversal(Tnode *node)
{
    // base cases
    if (node == NULL)
        return;

    // anticlockwise traversal
    cout << node->data << " ";

    // traverse the left boundary nodes excluding the leaf nodes
    printLeftBoundary(node->left);

    // traverse the leaf nodes using a inorder traversal
    printLeaves(node->left);
    printLeaves(node->right);

    // traverse the right boundary nodes excluding the leaf nodes from bottom to up
    printRightBoundary(node->right);

    cout << endl;
}

void verticalTraversal(Tnode *node)
{
    // base cases
    if (node == NULL)
        return;

    // using a map to get record
    map<int, map<int, multiset<int>>> nodes; // storing coordinates with the respective nodes

    // using a queue structure
    queue<pair<Tnode *, pair<int, int>>> queue; // storing coordinates wih respective nodes in the queue

    queue.push({node, {0, 0}}); // doing a level order traversal

    while (!queue.empty())
    {
        auto it = queue.front();
        queue.pop();
        Tnode *temp = it.first;
        int x = it.second.first;
        int y = it.second.second;
        nodes[x][y].insert(temp->data);
        if (temp->left)
        {
            // when going to left child we go a step back horizontally and one step forward vertically
            queue.push({temp->left, {x - 1, y + 1}});
        }
        if (temp->right)
        {
            // when going to right child we go a step forward horizontally and one step forward vertically
            queue.push({temp->right, {x + 1, y + 1}});
        }
    }
    // vector<vector<int>> ans;
    for (auto p : nodes)
    {
        vector<int> col;
        for (auto q : p.second)
        {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        printVector(col);
        // cout << endl;
    }
    // return ans;
}

// ? Morris Traversals

void MorrisInorder(Tnode *node)
{
    if (node == NULL)
        return;
    vector<int> inorder;
    Tnode *curr = node;

    while (curr != NULL)
    {
        // case 1 : if node->left == NULL print the current node and go right.
        if (curr->left == NULL)
        {
            inorder.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            Tnode *prev = curr->left;
            while (prev->right && prev->right != curr)
            {
                prev = prev->right; // right most node on the left subtree
            }
            // case 2: if left exists, make the right most node on the left subtree point to the curr node, then go left.
            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                // case 3:  severe the connection from curr and print the curr node and go right.
                prev->right = NULL;
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    cout << "Morris Inorder Traversal: " << endl;
    printVector(inorder);
}

void MorrisPreorder(Tnode *node)
{
    if (node == NULL)
        return;
    vector<int> preorder;
    Tnode *curr = node;

    while (curr != NULL)
    {
        // case 1 : if node->left == NULL print the current node and go right.
        if (curr->left == NULL)
        {
            preorder.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            Tnode *prev = curr->left;
            while (prev->right && prev->right != curr)
            {
                prev = prev->right; // right most node on the left subtree
            }
            // case 2: if left exists, make the right most node on the left subtree point to the curr node, print the node. then go left.
            if (prev->right == NULL)
            {
                prev->right = curr;
                preorder.push_back(curr->data);
                curr = curr->left;
            }
            else
            {
                // case 3:  severe the connection from curr and print the curr node and go right.
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
    cout << "Morris Preorder Traversal: " << endl;
    printVector(preorder);
}

// void MorrisPreorder2(Tnode *root)
// {
//     if (root == NULL)
//         return;

//     auto curr = root;
//     while (curr)
//     {
//         if (!curr->left)
//         {
//             Tnode *prev = curr->left;
//             while (prev->right)
//                 prev = prev->right;

//             prev->right = curr->right;
//             curr->right = curr->left;
//             curr->left = NULL;
//             cout << curr->data << " ";
//         }
//         curr = curr->right;
//     }
// }
