#include <iostream>

using namespace std;
class LinkedList {
  private:
    int data;
  LinkedList * node;
  friend class Driver_Class;
};
class Driver_Class {
  public:
    char * error = "error\n";
  LinkedList * createNode(int);
  void printList(LinkedList * temp) {
    while (temp != NULL) {
      cout << temp -> data << endl;
      temp = temp -> node;
    }
  }
  inline LinkedList * setNode(LinkedList * temp) {
    return temp -> node;
  }
LinkedList *DeleteFirstNode(LinkedList *start){
    LinkedList *tempStart;
    tempStart=start;
    if(start!=NULL){
       start=start->node;
       free(tempStart); 
       return start;
    }
    
    else{
        cout<<"The list is empty"<<endl;
    }
}  
void DeleteSpecificNode(int data,LinkedList *start){
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
   // free(tempStart);
}
  void setNumber(LinkedList * node, int n, Driver_Class & d1) {
    for (int i = 1; i <= n; i++) {
      node -> node = d1.createNode(i * 12);
      node = d1.setNode(node);
    }
  }
};
LinkedList * Driver_Class::createNode(int data1) {
  LinkedList * temp;
  try {
    temp = new LinkedList;
    if (temp) {
      temp -> data = data1;
      temp -> node = NULL;
      return temp;
    } else {
      throw error;
    }
  } catch (char * err) {
    cout << "Cannot create Node" << endl;
  }
}

int main() {
  Driver_Class *d1;
  LinkedList * node, * start, * temp;
  node = d1->createNode(11);
  start = node;
  d1->setNumber(node, 10, *d1);
  temp = start;
  d1->printList(temp);
  system("pause");
  system("cls");

  start=d1->DeleteFirstNode(start);
  temp=start;
  d1->printList(temp);
  system("pause");
  system("cls");

   d1->DeleteSpecificNode(72,temp);
   d1->printList(temp);
   system("pause");

}
