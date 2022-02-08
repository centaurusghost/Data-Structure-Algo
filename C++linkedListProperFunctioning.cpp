#include<iostream>
using namespace std;
// class LinkedList{
//     private:
//     int data; LinkedList *node;
//     friend class Driver_Class;
//     public:
//      ~LinkedList(){
   
//  }
// };
class Driver_Class{
private:
class LinkedList{
    private:
    int data; LinkedList *node;
    friend class Driver_Class;
    public:
     ~LinkedList(){
   
 }
};
char *err="Error\n";
static LinkedList *start;
public:
inline LinkedList *createNode();
void InsertNode();
void DeleteFirstNode();
void ReverseLinkedList();
void PrintListData();
void DeleteSpecificNode();
};
Driver_Class::LinkedList *Driver_Class::createNode(){
LinkedList *temp;
temp= new LinkedList;
temp->node=NULL;
return temp;
}
//Creates Nodes And Adds Values
void Driver_Class::InsertNode(){
LinkedList *temp, *tempStart;
int data;
cout<<"Enter Data To Be Inserted"<<endl;
cin>>data;
temp=createNode();
temp->data=data;
temp->node=NULL;
if(start==NULL){
    start=temp;
}
else{
    tempStart=start;
    while(tempStart->node!=NULL){
        tempStart=tempStart->node;
    }
    tempStart->node=temp;
}
}
//Deletes First Item Of Linked List
void Driver_Class::DeleteFirstNode(){
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
//Delete Data By searching
//Exits  if data not found
void Driver_Class::DeleteSpecificNode(){
    LinkedList *tempStart,*tempTempStart;
    int count = 0;
    int data;
    if(start==NULL){
        cout<<"The List Is Empty"<<endl;
        return;
    }
    // if(start->node==NULL and start->data==data){
    //     cout<<"Deleted 1st Element and No LinkedList Exists Anymore"<<endl;
    //     delete start;
    //     return;
    // }
    cout<<"Search & Delete for Data:";
    cin>>data;
    tempStart = start;
     if(start->data==data){
       start=start->node;
       delete tempStart;
       return;
    }
    tempTempStart= start;
    while(tempStart->data!=data){
        tempStart = tempStart->node;
        if(count!=0){
            tempTempStart=tempTempStart->node;
        }
        // if(tempStart==NULL & tempStart->data!=data){
        //     cout<<"Data Not Found"<<endl;
        //     return;
        // }
        count++;
    }
    tempStart=tempStart->node;
    tempTempStart->node=tempStart;
   // free(tempStart);
}
//Prints All Data Of A LinkedList
void Driver_Class::PrintListData(){
LinkedList *tempPrinter;
tempPrinter = start;
while(tempPrinter!=NULL){
    cout<<tempPrinter->data<<endl;
    tempPrinter= tempPrinter->node;
}
}
//Makes The LinkList In Reverse Order
void Driver_Class::ReverseLinkedList(){
LinkedList *temp1,*temp2;
temp1=temp2=NULL;
while(start!=NULL){
temp2=start->node;
start->node=temp1;
temp1=start;
start=temp2;
}
start=temp1;
}
Driver_Class::LinkedList *Driver_Class::start=NULL;
int main(){
Driver_Class *d1;
int *choice;
choice = new int;
while(1){
cout<<"Enter The Operations"<<endl;
cout<<"1.Insert Node In LinkedList"<<endl;
cout<<"2.Delete First Node in LinkedList"<<endl;
cout<<"3.Delete a Data Item From The LinkedList"<<endl;
cout<<"4.Print All Data Of LinkedList"<<endl;
cout<<"5.Reverse The LinkedList"<<endl;
cin>>*choice;
switch(*choice){
case 1:{
    d1->InsertNode();
    break;
}
case 2:{
d1->DeleteFirstNode();
    break;
}
case 3:{
d1->DeleteSpecificNode();
    break;
}
case 4:{
 d1->PrintListData();
    break;
}
case 5:{
d1->ReverseLinkedList();
    break;
}
default:
    return 0;
    break;

}
    system("pause");
    system("cls");
}
// d1->InsertNode(5);
// d1->InsertNode(6);
}
