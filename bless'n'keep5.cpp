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

    //calling non-virtual and virtual method inside the another method
    void iam1() {
        printf("I am ");
        printclass1();
    }
    void iam2() {
        printf("I am ");
        printclass2();
    }

    //non-virtual and virtual method
    void printclass1() {
        printf("Base1\n");
    }
    virtual void printclass2() {
        printf("Base2\n");
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
    void printclass1() {
        printf("Desc1\n");
    }
};
class Desc2 : public Base {
public:
    void show2() override {
        printf("Desc2 is shown()\n");
    }
    void printclass2() {
        printf("Desc2\n");
    }
};

int main()
{

    Base obj = Base();  //creates Base class object, calls its methods: Base.show1() and Base.show2();
    obj.show1();
    obj.show2();
    printf("\n");

    Base* objb = new Base();
    Base* obj1 = new Desc1();
    Base* obj2 = new Desc2();
    Desc1* objd1 = new Desc1();
    Desc2* objd2 = new Desc2();
    printf("\n");

    objb->printclass1();  //both times Base.printclass1()
    obj1->printclass1();
    printf("\n");

    objb->printclass2();  //Base.printclass2();
    obj2->printclass2();  //Desc2.printclass2();
    printf("\n");

    objd1->printclass1(); //Desc1.printclass1();
    objd2->printclass2(); //Desc2.printclass2();
    printf("\n");

    objd1->iam1();        //Base.iam1(), Base.printslass1() (not the Desc1.printclass1());
    objd2->iam2();        //Base.iam2(), Desc2.printslass2();
    printf("\n");

    Desc1 d1 = Desc1();
    d1.show1();            //Desc1.show1() is called
    d1.show2();            //Base.show2()
    printf("\n");

    Base* d2 = new Desc2();
    d2->show1();              //Base.show1()
    d2->show2();              //Desc2.show2()

    delete d2;                //~Base()
    printf("\n");
    return 0;
}
