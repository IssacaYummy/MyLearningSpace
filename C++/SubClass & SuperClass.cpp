#include <iostream>
#include <string>

class Animal
{
private:
    /* data */
public:
    std::string mouth;

    void eat();
    void sleep();
    void droll();

    Animal(/* args */);
    ~Animal();
};


Animal::Animal(/* args */)
{
}

Animal::~Animal()
{
}

class Pig : public Animal
{
private:
    /* data */
public:
    void climb();

    Pig(/* args */);
    ~Pig();
};

Pig::Pig(/* args */)
{
}

Pig::~Pig()
{
}

class Turtle : public Animal
{
private:
    /* data */
public:
    void swim();

    Turtle(/* args */);
    ~Turtle();
};

Turtle::Turtle(/* args */)
{
}

Turtle::~Turtle()
{
}

void Animal::eat()
{
    std::cout << "Eating..." << "\n" << std::endl;
}

void Animal::sleep()
{
    std::cout << "Sleeping..." << "\n" << std::endl;
}

void Animal::droll()
{
    std::cout << "Drooling.." << "\n" << std::endl;
}

void Pig::climb()
{
    std::cout << "Climbing..." << "\n" << std::endl;
}

void Turtle::swim()
{
    std::cout << "Swimming..." << "\n" << std::endl;   
}

int main()
{
    Pig pig;
    Turtle turtle;

    pig.climb();
    turtle.swim();
    
    return 0;
}