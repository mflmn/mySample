#include <iostream>

using namespace std;

void hanNuo(int num, char a, char b, char c)
{
    if(num == 1)
    {
        cout << "block:" << num <<","<< a <<"->"<< c << endl;
    }
    else
    {
        hanNuo(num-1, a, c, b);
        cout << "block:" << num <<"," << a << "->" << c << endl;
        hanNuo(num-1, b, a, c);
    }
}

int main(int argc, char** argv)
{
    cout << "hello" << endl;
    int blockNum = 3;
    char a = 'a';
    char b = 'b';
    char c = 'c';
    hanNuo(blockNum, a, b, c);

}
