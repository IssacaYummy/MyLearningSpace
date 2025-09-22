#include <iostream>

class lovers
{
public:
    void kiss(lovers *lover);
    void ask(lovers *lover, std::string sth);
    lovers(std::string theName);
protected:
    std::string name;

    friend class Others;
};

lovers::lovers(std::string theName)
    : name(theName)
{
    name = theName;
}

void lovers::kiss(lovers *lover)
{
    std::cout << name << " kisses " << lover->name << std::endl;
}

void lovers::ask(lovers *lover, std::string sth)
{
    std::cout << name << " asks " << lover->name << " for " << sth << std::endl;
}


class Boyfriend : public lovers
{
public:
    Boyfriend(std::string theName);
};

Boyfriend::Boyfriend(std::string theName)
    : lovers(theName)
{
    
}



class Girlfriend : public lovers
{
private:
    /* data */
public:
    Girlfriend(std::string theName);
};

Girlfriend::Girlfriend(std::string theName)
    : lovers(theName)
{

}


class Others
{
public:
    std::string name;
    Others(std::string theName);
    void kiss(lovers *lover);
};

Others::Others(std::string theName) : name(theName)
{
    name = theName;
}

void Others::kiss(lovers *lover)
{
    std::cout << name << " kisses " << lover->name << std::endl;
}

int main()
{
    Boyfriend boyfriend("Tom");
    Girlfriend grilfriend("Lucy");
    Others other("Jack");

    grilfriend.kiss(&boyfriend);
    boyfriend.ask(&grilfriend, "wash the dishes");
    
    std::cout << "But " << std::endl;
    
    other.kiss(&grilfriend);
    other.kiss(&boyfriend);

    return 0;
}


