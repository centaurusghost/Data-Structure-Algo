#include<iostream>
using namespace std;
int ReturnIndex(int a[],int index){
int min=a[index];
int temp=index;
for(int i=index+1; i<8; i++){
    if(min>a[i]){
        min=a[i];
        cout<<"Min="<<min<<endl;
        temp=i;
    }
   
}
return temp;
}
void print(int arr[]){
for(int i=0; i<8; i++){
    cout<<arr[i]<<" ";
}
}
void swap(int *x, int *y){
int temp;
temp=*x;
*x=*y;
*y=temp;
}
int main(){
int a[]={99,88,77,66,55,44,33,22,2};
int min;
for(int i=0; i<=6; i++){
    min=ReturnIndex(a,i);
    print(a);
    cout<<endl;
    swap(&a[i],&a[min]);
    print(a);
    cout<<endl;
}

print(a);
}