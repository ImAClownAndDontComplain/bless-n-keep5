#include <iostream>

using namespace std;

class Object
{
public:
    Object() { printf("Object is created\n"); }
    ~Object() { printf("Object is deleted\n"); }
};

class Base
{
public:
    Base() { printf("Base object is created\n"); }
    virtual ~Base() { printf("Base object is deleted\n"); }
};

class Desc : public Base
{
public:
    Object  obj;
    Desc() { printf("Desc object is created\n"); }
    ~Desc() { printf("Desc object is deleted\n"); }
};

int main()
{
    Base* b = new Desc();
    delete b;
    return 0;
}
