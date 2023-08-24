#include<iostream>
#include<vector>
using namespace std;
int main(){
    int num,bsize,i,m,n,element,temp;
    cin>>num;
    while(num--){
        cin>>bsize;
        vector<int> b;
        vector<int> a;
        for(i=0;i<bsize;i++){
            cin>>element;
            b.push_back(element);
        }
        a.push_back(b[0]);
        m=0,n=1;
        for(i=0;i<bsize-1;i++){
            temp=b[i]-1;
            if(b[i]-b[i+1]==0){
                a.push_back(b[i+1]);
            }
            else{
            while(temp>b[i+1]) temp--;
            if(temp!=0) a.push_back(temp);
            a.push_back(b[i+1]);
            }
        }
        cout<<a.size()<<endl;
        for(i=0;i<a.size();i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        a.clear();
        b.clear();
    }
}