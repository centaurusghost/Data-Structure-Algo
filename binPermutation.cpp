#include<iostream>
using namespace std;
void binPermut(int n, char A[]){
    static int count;
    count++;
if(n<1){
    cout<<count<<'.'<<A<<endl;
}
else{
A[n-1]='0';
binPermut(n-1,A);
A[n-1]='1';
binPermut(n-1,A);
}
}
main(){
char x[10];
x[10]='\0';
binPermut(10,x);
system("pause");
}