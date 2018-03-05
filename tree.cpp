#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct myTree
{
    char element;
    struct myTree *lTree, *rTree;
}myTree,*pMyTree;
int pos = -1;

void createTree(pMyTree *p, string str)
{
    pos++;
    if(pos < str.size())
    {
    //cout << pos << endl;
    //cout << str[pos]<<endl;
        if('#' == str[pos])
        {
            *p = NULL;
        }
        else
        {
            *p = (pMyTree) malloc(sizeof(myTree));
            (*p)->element = str[pos];
            createTree(&(*p)->lTree, str);
            createTree(&(*p)->rTree, str);
        }
    }



}

void preTravel(pMyTree p, int level)
{
    //cout << (*p)->element << endl;
    if(NULL != p)
    {
        cout << p->element << "-level:"<< level << endl;
        preTravel(p->lTree, level + 1 );
        preTravel(p->rTree, level + 1);
    }

}

void midTravel(pMyTree p, int level)
{
    if(NULL != p)
    {
        midTravel(p->lTree, level + 1);
        cout << p->element << "-level:" << level << endl;
        midTravel(p->rTree, level + 1);
    }
}

void postTravel(pMyTree p, int level)
{
    if(NULL != p)
    {
        postTravel(p->lTree, level + 1);
        postTravel(p->rTree, level + 1);
        cout << p->element << "-level:" << level << endl;
    }
}

int main(int argc, char** argv)
{
    int a[6] = {2,9,1,3,7,5};
    string s = "ABDG##H###CE#I##F##";
    pMyTree p = NULL;
    //int pos = -1;
    createTree(&p, s);
    cout << "tree create success" << endl;
    cout << &p << endl;
    preTravel(p,1);
    cout << "====mid=========="<< endl;
    midTravel(p,1);
    cout << "====post=========="<< endl;
    postTravel(p,1);
    cout<<"hello"<<endl;
}
