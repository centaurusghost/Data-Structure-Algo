#include<iostream>
using namespace std;

int gcd(int a, int b){
    if(a==b){
        return a;
    }
    if(a%b==0){
        return b;
    }
    if(b%a==0){
        return a;
    }
if(a>b){
    return gcd(a%b,b);
}
if(a<b){
     return gcd(a,b%a);
}}
main(){
cout<<gcd(42,20);
cout<<2%0;
}