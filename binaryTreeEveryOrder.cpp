#include <iostream>
using namespace std;
static int count = 0;
struct bin
{
    int data;
    bin *left;
    bin *right;
};

struct bin *createNode(int data)
{
    struct bin *rootNode;
    rootNode = new struct bin;
    if (rootNode)
    {
        rootNode->data = data;
        rootNode->left = NULL;
        rootNode->right = NULL;
        return rootNode;
    }
}

void preOrder(struct bin *rootNode)
{
    if (rootNode)
    {
        cout << rootNode->data << " ";
        //cin possible
        preOrder(rootNode->left);
        preOrder(rootNode->right);
    }
}
void inOrder(struct bin *rootNode)
{
    if (rootNode)
    {
        inOrder(rootNode->left);
        cout << rootNode->data << " ";
        inOrder(rootNode->right);
    }
}
void postOrder(struct bin *rootNode)
{
    if (rootNode)
    {
        postOrder(rootNode->left);
        postOrder(rootNode->right);
        cout << rootNode->data << " ";
    }
}

int main()
{
    struct bin *rootNode;
    rootNode = createNode(1);

    rootNode->left = createNode(2);
    rootNode->right = createNode(3);

    rootNode->left->left=createNode(4);
    rootNode->left->right=createNode(5);
    rootNode->right->left=createNode(6);
    rootNode->right->right=createNode(7);
    cout<<"Preorder traversal Binary Tree:";
    preOrder(rootNode);
    cout<<endl;
    cout<<"Inorder traversal Binary Tree:";
    inOrder(rootNode); cout<<endl;
    cout<<"Postorder traversal Binary Tree:";
    postOrder(rootNode); cout<<endl;
}
