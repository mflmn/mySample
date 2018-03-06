#include <iostream>
#include <pthread.h>

using namespace std;

class Area
{
public:
    int _len;
    static Area *_instance;
    static pthread_mutex_t _myLock;
public:
    Area();
    static Area *getInstance();
};

Area* Area::_instance = NULL;
pthread_mutex_t Area::_myLock;
Area::Area()
{
    pthread_mutex_init(&_myLock, NULL);
    cout << "construct" << endl;
}

Area* Area::getInstance()
{
    if(_instance == NULL)
    {
        pthread_mutex_lock(&_myLock);
        if(_instance == NULL)
        {
            _instance = new Area();
        }
        pthread_mutex_unlock(&_myLock);
    }
    return _instance;
}


int main(int argc, char** argv)
{
    cout << "hello" << endl;
    Area* p = Area::getInstance();
}
