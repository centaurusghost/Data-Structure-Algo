#include<iostream>
#include<windows.h>
using namespace std;
template<typename t1>
t1 *every;
struct arrayStack{
int top, capacity,*array;
};

struct arrayStack *createStack(int cap){
struct arrayStack *stack;
stack=(struct arrayStack*)malloc(sizeof(struct arrayStack));
stack->top=-1;
stack->capacity=cap;
stack->array=(int*)malloc(sizeof(int)*stack->capacity);
}

int isFull(struct arrayStack *stack){
if(stack->top==stack->capacity-1){
    return 1;
}
return 0;
}

int isEmpty(struct arrayStack *stack){
if(stack->top==-1){
    return 1;
}
return 0;
}

void push(struct arrayStack *stack, int item){
    if(!isFull(stack)){
        stack->top++;
        stack->array[stack->top]=item;
    }
    else{
        cout<<"Stack is FUll";
        system("pause");
    }
}

int pop(struct arrayStack *stack){
    int temp;
if(!isEmpty(stack)){
    temp=stack->array[stack->top];
    stack->top--;
    return temp;
}
else{
    cout<<"The stack is empty:";
    system("pause");
}
}

main(){

struct arrayStack *stack;
stack=createStack(1);
pop(stack);
push(stack,45);
cout<<pop(stack);

}