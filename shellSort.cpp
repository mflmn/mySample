#include <iostream>

using namespace std;

void shellSort(int a[])
{
    int length = 7;
    int gap = length / 2;
    for (; gap > 0; gap = gap / 2)
    {
        for (int m = 0; m < gap; m++)
        {

            for (int j = gap + m; j < length; j = j + gap)
            {
                for (int i = j; i > m; i = i - gap)
                {
                    if (a[i] < a[i - gap])
                    {
                        int temp = a[i];
                        a[i] = a[i - gap];
                        a[i - gap] = temp;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }
}

int main(int argc, char** argv)
{
    int a[] = {3,2,1,8,9,5,0};
    shellSort(a);
    for(int i = 0; i < 6;i++)
    {
        cout << a[i] << ",";
    }
    cout << a[6] << endl;
}
