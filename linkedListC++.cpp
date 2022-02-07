#include <iostream>

using namespace std;
class linkedList {
  public:
    int data;
  linkedList * node;
  friend class driver_Class;
};
class driver_Class {
  public:
    char * error = "error\n";
  linkedList * createNode(int);
  void printList(linkedList * temp) {
    while (temp != NULL) {
      cout << temp -> data << endl;
      temp = temp -> node;
    }
  }
  inline linkedList * setNode(linkedList * temp) {
    return temp -> node;
  }
  void setNumber(linkedList * node, int n, driver_Class & d1) {
    for (int i = 1; i <= n; i++) {
      node -> node = d1.createNode(i * 12);
      node = d1.setNode(node);
    }
  }
};
linkedList * driver_Class::createNode(int data1) {
  linkedList * temp;
  try {
    temp = new linkedList;
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
  driver_Class d1;
  linkedList * node, * start, * temp;
  node = d1.createNode(11);
  start = node;
  d1.setNumber(node, 10, d1);
  temp = start;
  d1.printList(temp);
}
