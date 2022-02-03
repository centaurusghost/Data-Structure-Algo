#include<iostream>
using namespace std;

struct bin{
int data;
bin *left;
bin *right;
};

bin *createNode(int data){
bin *rootNode;
rootNode= new bin;
if(rootNode){
rootNode->data= data;
rootNode->left=NULL;
rootNode->right=NULL;
return rootNode;
}
else{
    cout<<"Failed to create memory location"<<endl;
}
}

bin *searchData(bin *rootNode, int deta){
if(rootNode){
if(rootNode->data<deta){
return searchData(rootNode->right,deta);
}
else if(rootNode->data>deta){
    return searchData(rootNode->left,deta);
}
return (rootNode);
}
    if(rootNode==NULL){
    return NULL;
}
}

int main(){
    struct bin *rootNode,*temp;
    //filling raw data
    rootNode = createNode(45);

    rootNode->left = createNode(40);
    rootNode->right = createNode(60);

    rootNode->left->left=createNode(30);
    rootNode->left->right=createNode(35);

    rootNode->right->left=createNode(55);
    rootNode->right->right=createNode(65);
    //end of filling raw data for testing search
    //main 
    temp=searchData(rootNode,65);
    cout<<temp->data;
}