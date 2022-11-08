#include "treap.h"

int main()
{
    // srand(time(NULL));

    node *root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder traversal of the given tree \n";
    inorder(root);

    // cout << "\nPreorder traversal of the given tree \n";
    // preorder(root);

    // cout << "\nPostorder traversal of the given tree \n";
    // postorder(root);

    cout << "\nDelete 20\n";
    root = deleteNode(root, 20);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);

    cout << "\nDelete 30\n";
    root = deleteNode(root, 30);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);

    cout << "\nDelete 50\n";
    root = deleteNode(root, 50);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);

    node *res = search(root, 50);
    (res == NULL) ? cout << "\n50 Not Found " : cout << "\n50 found";

    return 0;
}