#include <iostream>
#include <stdlib.h>

using namespace std;

#define GET_ARRAY_LENGTH(a, len)        \
    {                                   \
        len = sizeof(a) / sizeof(a[0]); \
    }

int a[9] = {0};
int total = 0;

void hanNuo(int num, char a, char b, char c)
{
    if (num == 1)
    {
        cout << "block:" << num << "," << a << "->" << c << endl;
    }
    else
    {
        hanNuo(num - 1, a, c, b);
        cout << "block:" << num << "," << a << "->" << c << endl;
        hanNuo(num - 1, b, a, c);
    }
}

bool check(int i, int value)
{
    for (int j = 1; j < i; j++)
    {
        if ((a[j] == value) or (abs(a[j] - value) == abs(j - i)))
        {
            return false;
        }
    }
    return true;
}

void queen(int m)
{
    if (m <= 8)
    {
        for (int i = 1; i <= 8; i++)
        {
            a[m] = i;
            if (check(m, i))
            {
                if (m < 8)
                {
                    queen(m + 1);
                }
                else
                {
                    total++;
                }
            }
        }
    }
}

void quickSort(int a[], int left, int right)
{
    int i = left;
    int j = right;
    if (i < j)
    {
        int temp = a[left];
        while (i < j)
        {
            while (i < j)
            {
                if (a[j] < temp)
                {
                    a[i] = a[j];
                    i++;
                    break;
                }
                j--;
            }
            while (i < j)
            {
                if (a[i] > temp)
                {
                    a[j] = a[i];
                    j--;
                    break;
                }
                i++;
            }
        }
        a[i] = temp;
        quickSort(a, left, i - 1);
        quickSort(a, i + 1, right);
    }
}

void bubbleSort(int a[])
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7 - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void myMerge(int a[], int left, int mid, int right)
{
    int temp[7] = {0};
    int i = left;
    int j = mid + 1;
    int n = 0;
    while (i <= mid && j <= right)
    {
        if (a[i] <= a[j])
        {
            temp[n++] = a[i++];
        }
        else
        {
            temp[n++] = a[j++];
        }
    }
    while (i <= mid)
    {
        temp[n++] = a[i++];
    }
    while (j <= right)
    {
        temp[n++] = a[j++];
    }
    int m = 0;
    while (left <= right)
    {
        a[left++] = temp[m++];
        // m++;
    }
}

void mergeSort(int a[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, (mid + 1), right);
        myMerge(a, left, mid, right);
    }
}

void selectSort(int a[])
{
    for (int i = 0; i < 7; i++)
    {
        int temp = a[i];
        int min = i;
        for (int j = i + 1; j < 7; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        a[i] = a[min];
        a[min] = temp;
    }
}

void oldInsertSort(int a[])
{
    for (int i = 1; i < 7; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[i])
            {
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
}
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
        if(gap == 0)
        {
            break;
        }
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

int main(int argc, char **argv)
{
    // int blockNum = 3;
    // char a = 'a';
    // char b = 'b';
    // char c = 'c';
    // hanNuo( blockNum, a, b, c);
    //queen(1);
    //cout << "count:" << total << endl;
    int a[7] = {4, 2, 1, 8, 3, 5, 9};
    // cout << sizeof(a) / sizeof(int)<< endl;
    // int len;
    // GET_ARRAY_LENGTH(a, len);
    // cout << len << endl;
    // quickSort(a, 0, 6);
    // bubbleSort(a);
    // mergeSort(a, 0, 6);
    // selectSort(a);
    //insertSort(a);
    shellSort(a);
    sortPrint(a, 7);
}
