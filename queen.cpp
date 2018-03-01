#include <iostream>
#include <stdlib.h>

using namespace std;

int a[9] = {0};
int count = 0;

bool check(int row, int value)
{
    for(int i = 1; i < row; i++)
    {
        if((a[i] == value) or (abs(a[i] - a[row]) == abs(i - row)))
        {
            return false;
        }
    }
    return true;
}

void queen(int row)
{
    for(int j = 1; j <=8; j++)
    {
        a[row] = j;
        if(check(row, j))
        {
            if(row < 8)
            {
                queen(row + 1);
            }
            else
            {
                count++;
            }
        }
    }
}

int main(int argc, char** argv)
{
   cout << "hello" << endl;
   queen(1);
   cout << "count:" << count << endl;
}
