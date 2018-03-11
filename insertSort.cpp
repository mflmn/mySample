#include <iostream>

using namespace std;

void insertSort(int a[])
{
    for (int i = 1; i < 7; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (a[j] < a[j - 1])
            {
                int temp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = temp;
            }
            else
            {
                break;
            }
        }
    }
}

int main(int argc, char** argv)
{
    int a[7] = {2,4,1,3,7,9,5};
    for(int i = 1; i < 7; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(a[j] > a[i])
            {
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
    for(int m = 0; m < 7; m++)
    {
        cout << a[m]<<endl;
    }
}
