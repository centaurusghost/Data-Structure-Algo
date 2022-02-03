#include<iostream>
using namespace std;
struct node{
int data;
node *left ;
node *right;
};

struct node *createNode(int data){
struct node *rootNode = new node;
if(rootNode){
rootNode->data=data;
rootNode->left= NULL;
rootNode->right= NULL;
return rootNode;
}
}
void preOrder(node *rootNode){
if(rootNode){
cout<<rootNode->data<<" ";
preOrder(rootNode->left);
preOrder(rootNode->right);
}
}
main(){
struct node *rootNode;
rootNode=createNode(1);
rootNode->left=createNode(2);
rootNode->right=createNode(3);
rootNode->left->left=createNode(4);
rootNode->left->right=createNode(5);
rootNode->right->left=createNode(6);
rootNode->right->right=createNode(7);

preOrder(rootNode);
}