#include <iostream>

using namespace std;

class A
{
    public:
        virtual void show();
        void hao();
};

void A:: show()
{
    cout << " in the A" << endl;
}

void A::hao()
{
    cout << "hao in the A" << endl;
}

class B: public A
{
    public:
         virtual void show();
         void hao();
};

void B::hao()
{
    cout << "hao the B" <<endl;
}

void B::show()
{
    cout << "in the B" << endl;
}


int main(int argc, char** argv)
{

  A* c = new B();
  c->show();
  c->hao();
  //A a;
  //a.show();
  //B b;
  //b.show();
  return 0;
}
