#include<iostream>
using namespace std;
int tenth=24;
char result[24]={'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'};
int increment=24;
 int bin(int n){
  increment--;
if(n>1){
if(n%2==1){
  cout<<1;
   result[increment]='1';
  return bin(n/2);
}
cout<<0;
result[increment]='0';
return bin(n/2);
}
if(n==1){
  result[increment]='1';
  cout<<1;
}
if(n==0){
    result[increment]='0';
  cout<<0;
}  }
int main(){
bin(16777214);
cout<<endl;
for(int i=0; i<=23; i++){
    cout<<result[i];
}
}