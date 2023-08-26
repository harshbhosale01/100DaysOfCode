#include <iostream>
using namespace std;
int main(){
    long long int num,x,y,n,i;
    cin>>num;
    while(num--){
        cin>>x>>y>>n;
        int* arr=new int(n);
        long long int diff=1;
        arr[0]=x;
        arr[n-1]=y;
        for(i=n-2;i>0;i--){
            arr[i]=arr[i+1]-diff;
            diff++;
        }
        if(!(diff<=(arr[1]-arr[0]))) cout<<"-1"<<endl;
        else {
            for(i=0;i<n;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}