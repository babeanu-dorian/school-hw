#include <iostream>
#include "ptr/ptr.h"

using namespace std;

struct Base
{
    ~Base()         // not a virtual destructor
    {
        cerr << "Base destr.\n";
    }
};

struct Derived: public Base
{
    ~Derived()      // no overriding
    {
        cerr << "Derived's destructor\n";
    }
};

struct Derived2: public Base
{
    ~Derived2()     // no overriding
    {
        cerr << "Derived2's destructor\n";
    }
};

struct StandAlone
{};

int main()
{
    {
        Ptr<Base> p1(new Derived);
    }
    Ptr<Base> p2(new Derived2);
    p2.reset(new Derived);
	// fail: Ptr<Base> alone(new StandAlone);
}