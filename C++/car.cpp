#include <iostream>

class car
{
public:
    std::string color;
    std::string engine;
    float gas_tank;
    unsigned int Wheel;

    void fill_tank( float liter );
    void running(void);

};

void car::fill_tank( float liter )
{
    gas_tank += liter;
}


int main()
{
    char i;
    car mycar;

    mycar.color = "White";
    mycar.engine = "V8";
    mycar.Wheel = 4;
    mycar.gas_tank = 0;

    mycar.fill_tank(1);
    mycar.running();

    return 0;
}