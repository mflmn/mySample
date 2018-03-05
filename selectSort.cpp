#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    int a[7] = {2,4,1,3,7,9,5};
    int min;
    //int j;
    for(int i = 0; i < 7; i++)
    {
        //min = a[i];
        //int temp = a[i];
        min = i;
        for(int j = i+1; j < 7; j++)
        {
            if(a[j] < a[min])
            {
                //temp = a[j];
                min = j;
            }
        }
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    for(int m = 0; m < 7; m++)
    {
        cout << a[m]<<endl;
    }
}
