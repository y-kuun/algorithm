#include <iostream>
using namespace std;


class foo{
public:
	long a;
	long b;
	virtual void f(){cout<<"foo"<<endl;}
//	virtual void fv() = 0;
};

class goo: public foo{
public:
	long c;
	void f(){cout<<"goo"<<endl;}
};


int main(){
	int itg;
	int *p;
	cout<<sizeof(foo)<<endl;
	cout<<sizeof(goo)<<endl;
	foo fc;
	goo gc;
	fc.f();
	gc.f();
	cout<<sizeof(fc)<<endl;
	cout<<sizeof(gc)<<endl;
	itg = 10;
	p = &itg;
	cout<<*p<<endl;
	cout<<*(p-4)<<endl;
		//fc->fv();
	return 0;
}
