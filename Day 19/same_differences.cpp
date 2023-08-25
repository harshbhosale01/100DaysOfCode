#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    int num,len,i,element;
    long long int count;
    cin>>num;
    while(num--){
        cin>>len;
        map<long long int,long long int> umap;
        //vector<int> vec(len,0);
        count=0;
        for(i=0;i<len;i++){
            cin>>element;
            if(umap.find(element-i)!=umap.end()){
                count=count+umap[element-i];
            }
            if(umap.find(element-i)==umap.end()) umap[element-i]=1;
            else umap[element-i]++;
        }
        cout<<count<<endl;
        umap.clear();
    }
return 0;
}