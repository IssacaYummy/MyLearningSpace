#include <iostream>

class Pet
{
public:
    Pet(std::string theName);
    ~Pet();

    static int getCount();
protected:
    std::string name;
private:
    static int count;
};

int Pet::count = 0;     // 分配内存 初始化为0

class Dog : public Pet
{
public:
    Dog(std::string theName);
    ~Dog();
};

class Cat : public Pet
{
public:
    Cat(std::string theName);
    ~Cat();
};

Pet::Pet(std::string theName)
    : name(theName)
{
    count++;
    std::cout << "A pet named " << name << " is created!\n" << std::endl;
}

Pet::~Pet()
{
    count--;
    std::cout << "A pet named " << name << " is destroyed!\n" << std::endl;
}

int Pet::getCount()
{
    return count;
}

Dog::Dog(std::string theName)
    : Pet(theName)
{
    std::cout << "A dog named " << name << " is created!\n" << std::endl;
}

Dog::~Dog()
{
    std::cout << "A dog named " << name << " is destroyed!\n" << std::endl;
}

Cat::Cat(std::string theName)
    : Pet(theName)
{
    std::cout << "A cat named " << name << " is created!\n" << std::endl;
}

Cat::~Cat()
{
    std::cout << "A cat named " << name << " is destroyed!\n" << std::endl;
}

int main()
{
    Dog dog("Tom");
    Cat cat("Kitty");

    std::cout << "There are " << Pet::getCount() << " pets now. \n\n" << std::endl;

    {
        Dog dog2("Bob");
        Cat cat2("Lily");
        
        std::cout << "There are " << Pet::getCount() << " pets now. \n\n" << std::endl;
    }

    std::cout << "There are " << Pet::getCount() << " pets now. \n\n" << std::endl;

    return 0;
}