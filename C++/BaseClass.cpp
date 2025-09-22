#include <iostream>
#include <string>

class BaseClass
{
    public:
        BaseClass();
        ~BaseClass();

        void DoSomething();

};

class SubClass : public BaseClass
{
    public:
        SubClass();
        ~SubClass();
};

BaseClass::BaseClass()
{
    std::cout << "Into BaseClass Construct Function..." << "\n" << std::endl;
    std::cout << "Don Something in BaseClass Construct Function... " << "\n\n" << std::endl;
}

BaseClass::~BaseClass()
{
    std::cout << "Into BaseClass DeConstruct Function..." << "\n" << std::endl;
    std::cout << "Don Something in BaseClass DeConstruct Function... " << "\n\n" << std::endl;
}

void BaseClass::DoSomething()
{
    std::cout << "Do Sonmething ...\n\n" << std::endl;
}

SubClass::SubClass()
{
    std::cout << "Into SubClass Construct Function...\n\n" << std::endl;   
}

SubClass::~SubClass()
{
    std::cout << "Into SubClass Deconstruct Functino...\n\n" << std::endl;
}

int main()
{
    SubClass subclass;
    subclass.DoSomething();

    std::cout << "OVER!\n\n" << std::endl;

    return 0;
}