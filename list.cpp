#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct node
{
    char element;
    struct node *next;
}node;

void createList1(node** p, char a[])
{
    for(int i = 0; i < 5; i++)
    {
        node* temp = (node*)malloc(sizeof(node));
        temp->element = a[i];
        cout << temp << endl;
        *p = temp;
        *p = (*p)->next;
    }
}

void test(node** p)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->element = 'm';
    *p =temp;
    cout << "temp:" << temp << endl;
    //cout << p << endl;
}

void test1(node* p)
{
    p = (node*)malloc(sizeof(node));
    p->element = 'yyyyyyyy';
    cout << "y:" << p << endl;
    //cout << p << endl;
}

void createList(node* p, char a[])
{
    for(int i = 0; i < 5; i++)
    {
        p->element = a[i];
        p->next = (node*)malloc(sizeof(node));
        p = p->next;
    }
}

node* reverseList(node* p)
{
    node* pre = NULL;
    node* current = p;
    node* now = p;
    while(NULL != current)
    {
         node* next = current->next;
         //now = current;
         p = current;
         p->next = pre;
         pre = current;
         current = next;
         //cout << p->element << endl;
    }
    cout << p << endl;
    return p;
}

void reverseList1(node** p)
{
    node* pre = NULL;
    node* current = *p;
    while(NULL != current)
    {
         node* next = current->next;
         //now = current;
         *p = current;
         (*p)->next = pre;
         pre = current;
         current = next;
         //cout << p->element << endl;
    }
    cout << *p << endl;
}

int main(int argc, char** argv)
{
    char a[5] = {'1','2','3','4','5'};
    node* x = NULL;
    node* y = NULL;
    //test(&x);
    //test1(y);
    //cout << y << endl;
    node* p = (node*)malloc(sizeof(node));
    //cout << p->next << endl;
    node* head = p;
    cout << "head1:" << head << endl;

    createList(p, a);
    cout << "head2:" << head << endl;
    //node* headReverse = reverseList(head);
    reverseList1(&head);
    cout << "head**:" << head << endl;
    while(head != NULL)
    {
        cout << head->element << endl;
        head = head->next;
    }

    //cout << head->element << endl;
//    cout << "head3:" << head << endl;
//    while(headReverse != NULL)
//    {
//        cout << headReverse->element << endl;
//        headReverse = headReverse->next;
//    }
    //cout << head->next->element << endl;

/*
    node* p = NULL;
    node** head = &p;
    createList1(&p, a);
    cout << *head << endl;
    cout << p << endl;
    */
}
