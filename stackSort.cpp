#include <iostream>

using namespace std;

// template<class T>

// void stackSort(T& a)
// {
//     int length = sizeof(a)/sizeof(a[0]);
//     cout << length << endl;
// }
void stackSort(int a[], int length)
{
    int len = length;
    for(int i = 0; i< 6; i++)
    {
        for(int j = len/2 -1; j >= 0; j--)
        {
            int left = 2*j + 1;
            int right = 2*j +2;
            int large = j;
            if(left < len && a[large] < a[left])
            {
                large = left; 
            }
            if(right < len && a[large] < a[right])
            {
                large = right;
            }
            int temp = a[j];
            a[j] = a[large];
            a[large] = temp;
        }
        int temp = a[0];
        a[0] = a[len -1];
        a[len - 1] = temp;
        len--; 
    }
}

void sortPrint(int a[], int num)
{
    for (int i = 0; i < num - 1; i++)
    {
        cout << a[i] << ",";
    }
    cout << a[num - 1] << endl;
}

int main(int argc, char** argv)
{
    cout << "stack" << endl;
    int a[7] = {6,2,9,1,3,5,4};
    stackSort(a, 7);
    sortPrint(a,7);
    char aa;
    cin >> aa;
}