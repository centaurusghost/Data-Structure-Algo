#include<iostream>
using namespace std;
class linkedList{
	private: char *error="Error\n";
	public:
		int data; linkedList *node;
	    	linkedList *createNode(int data1){
		   linkedList *temp;
		   try{
		   	temp = new linkedList;
		   	if(temp){
		   		temp->data=data1;
			temp->node=NULL;
			return temp;
			   }
			   else{
			   	throw error;
			   }
		   }
		   catch(char *err){
		   	cout<<"Cannot create Node"<<endl;
		   }
			
		}
		
		void printList(linkedList *temp){
			while(temp!=NULL){
				cout<<temp->data<<endl;
				temp=temp->node;
			}
		}
	inline	linkedList *setNode(linkedList *temp){
			return temp->node;
		}
};
int main(){
	linkedList *node, *temp,*start;
	node = node->createNode(11);
    start = node;
	for(int i=1; i<=3; i++){
		node->node=node->createNode(i*12);
		node = node->setNode(node);	                 
	}
	temp=start;
	node->printList(temp);
	
}                  
