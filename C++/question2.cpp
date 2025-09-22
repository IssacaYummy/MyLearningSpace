#include <iostream>

int main()
{
    const unsigned short ADD_SUBTRACT = 32;
    const double RATIO = 9.0/5.0;

    double tempIn , tempOut;
    char TypeIn, TypeOut;

    std::cout << "[xx.x C] or [xx.x F] to input tempurature:";
    std::cin >> tempIn >> TypeIn;
    std::cin.ignore(100,'\n');
    std::cout << "\n";

    switch ( TypeIn )
    {
    case 'C':
    case 'c':
        tempOut = tempIn * RATIO + ADD_SUBTRACT;
        TypeOut = 'F';
        TypeIn = 'C';
        break;
    case 'F':
    case 'f':
        tempOut = ( tempIn - ADD_SUBTRACT ) / RATIO;
        TypeOut = 'C';
        TypeIn = 'F';
        break;
    default:
        TypeOut = 'E';
        break;
    }

    if(TypeOut != 'E')
    {
        std::cout << tempIn << TypeIn << " = " << tempOut << TypeOut << "\n\n";
    }
    else
    {
        std::cout << "INPUT ERROR" << "\n\n";
    }


}