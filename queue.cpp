#include<iostream>
using namespace std;
struct arrayQueue{
int front, rear, *array, capacity;
};

struct arrayQueue *createQueue(int cap){
struct arrayQueue *q;
q=(struct arrayQueue*)malloc(sizeof(struct arrayQueue));
q->front=q->rear=-1;
q->capacity=cap;
q->array=(int*)malloc(sizeof(int)*cap);
if(!q->array){
    cout<<"Problem"<<endl;
    system("pause");
}
else{
    return q;
}
}

int isEmpty(struct arrayQueue *q){
    if(q->front==-1){
        return 1;
    }
    return 0;
}

int isFull(struct arrayQueue *q){
 if((q->rear+1)%q->capacity==q->front){
     return 1;
 }
 return 0;
}

int qSize(struct arrayQueue *q){
return(
(q->capacity-q->front+q->rear)%q->capacity
);
}

int enQueue(struct arrayQueue *q, int item){
if(!isFull(q)){
    q->rear=(q->rear+1)%q->capacity;
    q->array[q->rear]=item;
    if(q->front==-1){
        q->front=q->rear;
    }
}
else{
    cout<<"No more space"<<endl;
    system("pause");
}

}

int deQueue(struct arrayQueue *q){
    int item;
if(!isEmpty(q)){
item=q->array[q->front];
if(q->front==q->rear){
    q->front=q->rear=-1;
}
else{
    q->front=(q->front+1)%q->capacity;
}

}
else{ 
    cout<<"queue is empty"<<endl;
    system("pause");
    return -1;
}
return item;
}

void deleteQueue(struct arrayQueue *q){
if(q){
    if(q->array){
        free(q->array);
    }
    free(q);
    cout<<"Queue deleted sucessfully"<<endl;
    system("pause");
}

}


int main(){
struct arrayQueue *q;
q=createQueue(5);
int temp, item;
while(1){
    system("cls");
cout<<"1. Enqueue"<<endl;
cout<<"2. Dnqueue"<<endl;
cout<<"3. Squeue"<<endl;
cout<<"4. DeletQ"<<endl;
cout<<"5. Exit"<<endl;
cin>>temp;
switch(temp){
case 1:{
    cout<<3%6;
    cout<<"Enter val:";
    cin>>item;
    enQueue(q,item);
    break;
}
case 2:{
   item=deQueue(q);
   cout<<"Dequed item is:"<<item<<endl;
   system("pause");
    break;
}
case 3:{
    cout<<"The queue size is:"<<qSize(q);
    system("pause");
    break;
}
case 4:{
    deleteQueue(q);
    break;
}
case 5:{
    return 0;
    break;
}
}
}
}