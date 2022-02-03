#include<iostream>
#include<string.h>
using namespace std;

void swap(char *x, char *y){
char ch;
ch = *x;
*x=*y;
*y=ch;
}
int permutation(char *s, int i, int n){
static int count; int j;
if(i==n){
count++;
cout<<count<<'.'<<s<<endl;
}
else{
for(j=i; j<=n; j++){
swap((s+i),(s+j));
permutation(s,i+1,n);
swap((s+i),(s+j));
}
}
}

main(){
   char *str;
   gets(str);
   permutation(str,0,strlen(str)-1);
}