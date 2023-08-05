#include<iostream>
using namespace std;
int main(){
int test,len,i,max=0,num,prev=0;
bool sorted;
cin>>test;
while(test--){
    cin>>len;
    max=0;
    sorted=1;
    prev=0;
    //int *arr=new int(len);
    for(i=0; i<len; i++){
        cin>>num;
        if(prev>num) {
            sorted = 0;
            if(max<prev) max = prev;
            }
        prev=num;
    }
    if(sorted) cout<<"0\n";
    else cout<<max<<"\n";
}
return 0;
}