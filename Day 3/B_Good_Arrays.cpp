#include <iostream>
using namespace std;

int main()
{
    int test, len, i, num;
    long long int sum;
    cin >> test;
    while (test--)
    {
        cin >> len;
        sum = 0;
        /*if (len == 1)
        {
            cout << "NO0\n";
            sum=0;
            // break;
            // continue;
        }*/
        //else
       // {
            for (i = 0; i < len; i++)
            {
                cin >> num;
                sum += num;
            }
            if (len==1) cout << "NO\n";
            else if ((int)sum / len == 1)
                cout << "NO\n";
            else
                cout << "YES\n";
      //  }
    }
    return 0;
}