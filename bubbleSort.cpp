#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    int a[7] = {2,4,1,3,7,9,5};
    int temp = 0;
    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 7-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    for(int m = 0; m < 7; m++)
    {
        cout << a[m]<<endl;
    }
}
