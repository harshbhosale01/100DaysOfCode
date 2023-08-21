#include <iostream>
#include <string>
using namespace std;
int main(){
    string num;
    cin>>num;
    int i=num.size()-1;
    while(i>0){
        if((*(num.begin()+i))>'4') {
            *(num.begin()+i)=(('9'-(*(num.begin()+i)))+'0');
        }
        i--;
    }
    if(*num.begin()!='9' && *(num.begin())>'4') {
        *(num.begin())=(('9'-(*(num.begin())))+'0');
    }
    cout<<num<<endl;
    return 0;
}