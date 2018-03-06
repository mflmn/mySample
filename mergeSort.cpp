#include <iostream>

using namespace std;





void merge(int *a, int left, int mid, int right, int *temp)
{
    int i = left;
    int j = mid + 1;
    int m = 0;
    while(i <= mid && j <= right)
    {
        if(a[i] <= a[j])
        {
            temp[m++] = a[i++];
        }
        else
        {
            temp[m++] = a[j++];
        }
    }
    while(i <= mid)
    {
        temp[m++] = a[i++];
    }
    while(j <= right)
    {
        temp[m++] = a[j++];
    }
    int t = 0;
    while(left <= right)
    {
        a[left++] = temp[t++];
    }
}

void sort(int *a, int left, int right, int *temp)
{
    if(left < right)
    {
        int mid = (left + right) / 2;
        sort(a, left, mid, temp);
        sort(a, mid+1, right, temp);
        merge(a,left, mid, right, temp);
    }
}

void start(int a[])
{
    int temp[9] = {0};
    sort(a, 0, 8, temp);

}

int main(int argc, char** argv)
{
    int a[9] = {3,5,2,8,1,6,4,9,7};
    int temp[9] = {0};
    start(a);
    for(int n = 0; n < 9 ; n++)
    {
        cout << a[n]<< endl;
    }
    //sort(a,0, 8, temp);
}
