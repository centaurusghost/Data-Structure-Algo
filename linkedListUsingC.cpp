#include<iostream>
using namespace std;

struct linkedList{
int data;
linkedList *node;
};

linkedList *createNode(int data){
    linkedList *node;
    node = new linkedList;
    node->data=data;
    node->node=NULL;
    return node;
}
int main(){
linkedList *node, *start, *temp;;
node = createNode(11);
start=node;
for(int i=1; i<=2; i++){
    node->node = createNode(i*22);
    node = node->node;  
}
temp=start;
while(temp!=NULL){
    cout<<temp->data<<endl;
    temp = temp->node;
}
}
