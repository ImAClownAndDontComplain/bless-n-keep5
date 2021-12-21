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
		auto p3 = make_unique<object>();
		   //auto p4 = p3 - impossible
		auto cpy = move(p1); // p1 is empty now
		p3 = move(p1);       // p3 is empty too(the object of p3 is deleted)

	}
	printf("\n");
	{
		shared_ptr<object> p1(new object());
		shared_ptr<object> p2(p1);  //2 strong refs
		shared_ptr<object>p3;
		p1 = move(p3);              //p1 is empty; 1 strong ref(p2)
		p2 = move(p3);              //p2 is empty; object is deleted;
	}
}
