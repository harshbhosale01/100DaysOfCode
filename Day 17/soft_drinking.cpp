#include<iostream>
#include <algorithm>
using namespace std;
int main(){
    int n,k,l,c,d,p,nl,np,result;  
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;
    int x=(k*l)/nl;
    int y=c*d;
    int z=(p/np);
    result=min(x,y);
    result=min(result,z)/n;
    cout<<result<<endl;
    return 0;
}