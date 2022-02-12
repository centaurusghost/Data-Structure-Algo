#include<iostream>
using namespace std;
int main(){
int a[8]={43,34,57,86,123,44,99,88};
int temp;
for(int i=1; i<8; i++){
temp=a[i];
for(int j=i-1; j>=0; j--){
if(temp<a[j]){
a[j+1]=a[j];
a[j]=temp;
    }
    else{
        break;
    }

}
}
for(int i=0; i<8; i++){
    cout<<a[i]<<" ";
}
}