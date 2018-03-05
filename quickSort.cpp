#include <iostream>

using namespace std;

void qSort(int* a, int left, int right)
{
    int i =  left;
    int j = right;
    if(left < right)
    {
        int temp = a[left];
        while(i < j)
        {
            for(j; i < j;j--)
            {
                if(a[j] < temp)
                {
                    a[i] = a[j];
                    i++;
                    break;
                }
            }
            for(i; i < j; i++)
            {
                if(a[i] > temp)
                {
                    a[j] = a[i];
                    j--;
                    break;
                }
            }

        }
        a[i] = temp;
        qSort(a, left, i - 1);
        qSort(a, i+1, right);
    }
}

int main(int argc, char** argv)
{
    cout << "hello" << endl;
    int a[8] = {5,2,1,6,9,3,7,8};
    int b[1] = {2};
    int i = 0;
    int j = 7;
    qSort(a, i, j);
    //qSort(b, 0, 0);
    //for(int x = 0; x <=j; x++)
    for(int x = 0; x <=j; x++)
    {
        cout << a[x] << endl;
    }
    return 0;
}
