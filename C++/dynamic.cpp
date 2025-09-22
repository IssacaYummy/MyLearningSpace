#include <iostream>
#include <string>

class Company
{
public:
    Company(std::string name)
    {
        this->name = name;
    }
    virtual void printInfo()
    {
        std::cout << "Company Name: " << name << std::endl;
    }
    virtual ~Company()
    {
        std::cout << "Company " << name << " is being deleted." << std::endl;
    }
protected:
    std::string name;
};

class TechCompany : public Company
{
public:
    TechCompany(std::string name, std::string product)
     : Company(name)
    {
        this->product = product;
    }
    virtual void printInfo() override
    {
        std::cout << "Tech Company Name: " << name << ", Product: " << product << std::endl;
    }
    virtual ~TechCompany()
    {
        std::cout << "Tech Company " << name << " is being deleted." << std::endl;
    }
private:
    std::string product;
};

int main()
{
    Company* company = new Company("APPLE");
    company -> printInfo();

    delete company;

    company = new TechCompany("Google", "Search Engine");
    company -> printInfo();

    delete company;
    company = NULL;

    return 0;
}
