#include <iostream>


class Base {
public:
    Base() {
        printf("Base object is created\n");
    }
    virtual void show1() {
        printf("Object is shown(1)\n");
    }
    virtual void show2() {
        printf("Object is shown(2)\n");
    }
    void printclass() {
        printf("Base\n");
    }
    ~Base() {
        printf("Base object is deleted\n");
    }
};
class Desc1 : public Base {
public:
    void show1() override {
        printf("Desc1 is shown()\n");
    }
    void printclass() {
        Base::printclass();
        printf("Desc1\n");
    }
};
class Desc2 : public Base {
public:
    void show2() override {
        printf("Desc2 is shown()\n");
    }
};

int main()
{

    Base obj = Base();  //creates Base class object, calls its methods: Base.show1() and Base.show2();
    obj.show1();
    obj.show2();

    Desc1 d1 = Desc1(); //creates Desc1 class object using Base class' constructor 
    d1.show1();         //Desc1.show1() is called
    d1.printclass();    //Base.printclass(), then Desc1.printclass()
    d1.show2();         //Base.show2()

    Base* d2 = new Desc2();   //again only Base's constructor is used
    d2->show1();              //Base.show1()
    d2->printclass();         //Base.printclass()
    d2->show2();              //Desc2.show2()
    delete d2;                //~Base()

    return 0;
}
