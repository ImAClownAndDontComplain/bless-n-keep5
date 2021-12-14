#include <iostream>

using namespace std;

class Base {
public:
	Base() {
		printf("Base()\n");
	}
	Base(Base* obj) {
		printf("Base(pointer)\n");
	}
	Base(Base& obj) {
		printf("Base(reference)\n");
	}
	~Base() {
		printf("~Base()\n");
	}
};

class Desc : public Base {
public:
	Desc() {
		printf("Desc()\n");
	}
	Desc(Desc* obj) {
		printf("Desc(pointer)\n");
	}
	Desc(Desc& obj) {
		printf("Desc(reference)\n");
	}
	~Desc() {
		printf("~Desc()\n");
	}
};

void f1(Base obj) {
	printf("f1: creating a copy of a Base class object\n");
}
void f2(Base* obj) {
	printf("f2: using a pointer to a Base class object\n");
}
void f3(Base& obj) {
	printf("f3: using a Base class object reference\n");
}

Base bf1() {
	printf("bf1: returns a Base object\n");
	Base b;
	return b;
}
Base* bf2() {
	printf("bf2: returns a pointer to a Base class object\n");
	Base* b = new Base();
	return b;
}
Base& bf3() {
	printf("bf2: returns a Base class object reference\n");
	Base b;
	return b;
}

int main() {
	Base b1;
	Base* b = new Base();
	Base b2(b);
	Base b3(*b);
	printf("\n");

	Desc d1;
	Desc* d = new Desc();
	Desc d2(d);
	Desc d3(*d);
	printf("\n");

	f1(b1);
	f2(b);
	f3(*b);
	printf("\n");

	f1(d1);
	f2(d);
	f3(*d);
	printf("\n");

	bf1();
	bf2();
	bf3();
	printf("\n");
	delete b;
	return 0;
}