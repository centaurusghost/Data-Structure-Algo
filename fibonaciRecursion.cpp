#include<iostream>
using namespace std;
int fib(int n){
if(n>2){
    return fib(n-1)+fib(n-2);
}
if(n==1 or n==2){
    return 1;
}
}
main(){
    int n=5;
    for(int i=1; i<=n; i++){
       cout<<fib(i); 
    }
  
}