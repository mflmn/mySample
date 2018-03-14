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

class Area
{
public:
    int _len;
    static Area *_instance;
public:
    Area();
    static Area *getInstance();
};

Area* Area::getInstance()
{
    if(_instance == NULL)
    {
        _instance = new Area();
        return _instance;
    }
    return _instance;
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
