#include <iostream>
using namespace std;
int main()
{
    int mat[5][5],i=0,j=0,result;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            cin>>mat[i][j];
            if(mat[i][j]==1) {
                result=abs(2-i)+abs(2-j);
            }
        }
    }
    cout<<result<<endl;
}