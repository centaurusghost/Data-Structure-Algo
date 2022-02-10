#include <iostream>
using namespace std;

struct DoulbyLinkedList
{
    DoulbyLinkedList *prev;
    // will point to previous memory block
    int data;
    DoulbyLinkedList *next;
    // will point to next memory block
};
inline DoulbyLinkedList *CreateNode()
{
    DoulbyLinkedList *temp;
    temp = (DoulbyLinkedList *)(malloc(sizeof(DoulbyLinkedList)));
    return temp;
}
void InsertAtFirstNode(DoulbyLinkedList **start){
    DoulbyLinkedList *temp, *p;
    int data;
    cout<<"Enter data"<<endl;
    cin>>data;
    if(*start!=NULL){
    temp=*start;
    p=CreateNode();
    temp->prev=p;
    p->next=temp;
    *start=p;
    p->prev=*start;
    p->data=data;
    cout<<"created"<<endl;
    system("pause");
   // delete temp;
    return;
    }
    
    else{
        cout<<"First node created"<<endl;
        system("pause");
        temp=CreateNode();
        *start=temp;
        temp->next=NULL;
        temp->prev=*start;
        temp->data=data;
       return; 
    }
   
}
void InsertNode(DoulbyLinkedList **start)
{
    int data;
    DoulbyLinkedList *temp1, *temp2;
    temp1 = CreateNode();
    cout << "Enter data:";
    cin >> data;
    if (*start != NULL)
    {
        temp2 = *start;
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp1;
        // prev and next address
        temp2->next->prev = temp2;
        temp2->next->data = data;
        temp2->next->next = NULL;
    }
    else
    {
        *start = temp1;
        temp1->data = data;
        temp1->prev = *start;
        temp1->next = NULL;
    }
}
void PrintLinkedList(DoulbyLinkedList **start)
{
    if (*start != NULL)
    {
        DoulbyLinkedList *temp;
        temp = *start;
        while (temp != NULL)
        {
            cout << temp->prev << " " << temp->data << " " << temp->next << endl;
            temp = temp->next;
        }
    }
    else if(*start==NULL)
    {
        cout << "The list is Empty" << endl;
        return;
    }
}

void DeleteSpecificNode(DoulbyLinkedList **start)
{
DoulbyLinkedList *temp1;
int data;
temp1=*start;
 cout<<"Enter data to Be Deleted:";
    cin>>data;
if(*start==NULL){
    cout<<"The list is empty"<<endl;
    system("pause");
    return;
}
if(*start!=NULL & temp1->next!=NULL){
    while(temp1->next!=NULL){
        if(temp1->data==data){
            cout<<"Data found"<<temp1->data<<endl;
            system("pause");
         break;
        }
        temp1=temp1->next;
    }
    if(temp1->next!=NULL){
        if(temp1==*start){
            cout<<"Deletion At First Node"<<endl;
            *start=temp1->next;
            delete temp1;
            return;
        }
    temp1->prev->next=temp1->next;
    temp1->next->prev=temp1->prev;
    delete temp1;
        return;
    }
    else if(temp1->next==NULL){
        temp1->prev->next=NULL;
     delete temp1;
     return;
    }
}
else {
if(temp1->next==NULL){
*start=NULL;
delete temp1;
return;
}
}
}

void SearchAndEditData(DoulbyLinkedList **start){
DoulbyLinkedList *temp;
int data;
cout<<"Enter data to search and edit"<<endl;
cin>>data;
temp=*start;
while(temp!=NULL){
    if(temp->data==data){
        break;
    }
    temp=temp->next;
}
if(temp->data==data){
    cout<<"Data found"<<endl;
    cout<<"Enter new data:";
    cin>>data;
    temp->data=data;
    return;
}
else{
    cout<<"The specific data not found"<<endl;
    system("pause");
    return;
}
 }
 void DeleteLastLeaf(DoulbyLinkedList **start){
DoulbyLinkedList *temp;
temp=*start;
if(temp!=NULL){
    if(temp->next!=NULL){
while(temp->next!=NULL){
temp=temp->next;
}
temp->prev->next=NULL;
delete temp;
return;
    }
    else{
        *start=NULL;
        delete temp;
    }

}
else{
    return;
}

 }   
int main()
{
    DoulbyLinkedList *start = NULL;
    int choice;
    while (1)
    {
        cout << "1.Insert Node" << endl;
        cout << "2.Print List" << endl;
        cout << "3.Delete Specific Data" << endl;
        cout<<"4.Insert At first Node"<<endl;
        cout<<"5. Search and edit data"<<endl;
        cout<<"6.Delete At End"<<endl;

        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            InsertNode(&start);
            break;
        }
        case 2:
        {
            PrintLinkedList(&start);
            system("pause");
            break;
        }
        case 3:
        {
            DeleteSpecificNode(&start);
        }
        case 4:{
       InsertAtFirstNode(&start);
            break;
        }
        case 5:{
            SearchAndEditData(&start);
        }
        case 6:{
            DeleteLastLeaf(&start);
        }
        }
        system("cls");
    }
}
