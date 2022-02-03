#include<iostream>
using namespace std;
void toh(int n,char beg, char aux, char end){
if(n>=1){
toh(n-1,beg,end,aux);
cout<<beg<<" "<<end;
toh(n-1,aux,beg,end);
}
}

main(){
toh(64,'m','a','d');
    
}