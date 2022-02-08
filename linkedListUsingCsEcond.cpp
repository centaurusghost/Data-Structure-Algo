#include<iostream>
using namespace std;
struct LinkedList{
int data;
 LinkedList *node;
};
LinkedList *start = NULL;
LinkedList * CreateNode(){
    LinkedList *temp;
    temp = (LinkedList *)(malloc(sizeof(LinkedList)));
    return temp;
}
void InsertNode(int data){
    LinkedList *temp,*tempStart;
    temp=CreateNode();
    temp->data=data;
    temp->node=NULL;
    if(start==NULL){
     start=temp;
    }
    else{
tempStart = start;
while(tempStart->node!=NULL){
    tempStart=tempStart->node;
}
tempStart->node = temp;
    }
}
void PrintListData(){
LinkedList *tempPrinter;
tempPrinter = start;
while(tempPrinter!=NULL){
    cout<<tempPrinter->data<<endl;
    tempPrinter= tempPrinter->node;
}
}
void DeleteFirstNode(){
    LinkedList *tempStart;
    tempStart=start;
    if(start!=NULL){
       start=start->node;
       free(tempStart); 
    }
    else{
        cout<<"The list is empty"<<endl;
    }
}

void DeleteSpecificNode(int data){
    LinkedList *tempStart,*tempTempStart;
    int count = 0;
    tempStart = start;
     if(start->data==data){
       start=start->node;
       free(tempStart); 
       return;
    }
    tempTempStart= start;
    while(tempStart->data!=data){
        tempStart = tempStart->node;
        if(count!=0){
            tempTempStart=tempTempStart->node;
        }
        count++;
    }
    tempStart=tempStart->node;
    tempTempStart->node=tempStart;
   // free(tempTempStart);
}
int main(){
InsertNode(11);
InsertNode(22);
InsertNode(33);
InsertNode(44);
InsertNode(55);

DeleteSpecificNode(44);
PrintListData();
system("pause");

DeleteSpecificNode(11);
system("cls");
PrintListData();
}
