#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int num, n, m, i, j, c = 0,pass=0;
    cin >> num;
    string str = {'v', 'i', 'k', 'a'};
    
    while (num--)
    {
        c=0;
        cin >> n; //row 
        cin >> m; //column
        //  vector<vector<int>> vec(n, vector<int>(m));
        char* vec= new char(n*m);
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                cin >> vec[i*m+j];
                //cout<<  vec[i*m+j]<<" ";
            }
        }
        for (i = 0; i < m; i++) //column
        {   
            pass=0;
            for (j = 0; j < n ; j++) //row
            {   
                //cout<< vec[j*m+i]<<" ";
                if (vec[j*m+i] == str[c])
                {
                    pass=1;
                    break;
                }
                if(c==4) break;
            }
            if(pass==1 && c<4) c++;
        }
        delete[] vec;
        if(c==4) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}