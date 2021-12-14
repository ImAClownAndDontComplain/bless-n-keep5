#include <iostream>
#include <string>

using namespace std;

class classA {
public:
	classA() {}
	virtual string getType() {
		return "A";
	}
	virtual bool isA(string type) {
		return(type == "A");
	}
};

class classB :public classA {
public:
	classB() {}
	string getType() {
		return "B";
	}
	bool isA(string type) {
		if (type == "B")return true;
		return classA::isA(type);
	}
	void Bmeth() {
		printf("Hello B\n\n");
	}
};

class classC :public classA {
public:
	classC() {}
	string getType() {
		return "C";
	}
	bool isA(string type) {
		if (type == "C")return true;
		return classA::isA(type);
	}
	void Cmeth() {
		printf("Hello C\n\n");
	}
};

class classD :public classA {
public:
	classD() {}
	string getType() {
		return "D";
	}
	bool isA(string type) {
		if (type == "D")return true;
		return classA::isA(type);
	}
	void Dmeth() {
		printf("Hello D\n\n");
	}
};

int main() {
	classA* objects[4] = {new classA(), new classB(), new classC(),new classD()};
	for (int i = 0; i < 4; i++) {
		if (objects[i]->getType()=="B") {
			((classB*)(objects[i]))->Bmeth();
		}
		if (dynamic_cast<classC*>(objects[i])!=nullptr) {
			dynamic_cast<classC*>(objects[i])->Cmeth();
		}
		if(objects[i]->isA("D"))((classD*)(objects[i]))->Dmeth();
	}
}
