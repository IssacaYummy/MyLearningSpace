#include <iostream>
#include <string>

class MyClass
{
public:
    MyClass(int *p)
    {
        ptr = p;
    }
    ~MyClass()
    {
        delete ptr;
    }

    MyClass &operator=(const MyClass &rhs)
    {
        if(this != &rhs)
        {
            int *new_ptr = new int(*(rhs.ptr)); // Allocate and copy first
            delete ptr;                         // Then delete old data
            ptr = new_ptr;                      // Update pointer
        }
        else
        {
            std::cout << "Self-assignment detected.\n" << std::endl;
        }

        return *this;
    }

    void print()
    {
        std::cout << "Value:" << *ptr << std::endl;
        std::cout << "Address:" << ptr << std::endl;
    }
private:
    int *ptr;
};

int main()
{
    MyClass obj1(new int(1));
    MyClass obj2(new int(2));

    obj1.print();
    obj2.print();

    obj2 = obj1;

    obj1.print();
    obj2.print();

    return 0;
}
