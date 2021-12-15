#include <iostream>

using namespace std;

class object {
public:
	object() {
		printf("Object is created\n");
	}
	~object() {
		printf("Object is deleted\n");
	}
};

int main()
{
	object* o1 = new object();
	object* o2 = o1;
	delete o1;
	//delete o2;
	{
		unique_ptr<object> p1(new object());
		//unique_ptr<object> p2(p1); - impossible
		unique_ptr<object> p3;
		p3 = move(p1);
		//p3.swap(p1)
	}
	{
		shared_ptr<object> p1(new object());
		shared_ptr<object> p2(p1);
	}
}
