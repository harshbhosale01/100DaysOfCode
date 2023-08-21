#include <iostream>
using namespace std;
int main(){
    char str[3];
    int n,count=0;
    cin>>n;
    while(n--){
        cin>>str;
        if(str[1]=='+') count++;
        else count --;
    }
    cout<<count<<endl;
}