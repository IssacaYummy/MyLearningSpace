#include <iostream>

int main()
{
    char answer;

    std::cout << "请问可以格式化您的硬盘吗？y/n" << "\n";
    std::cin >> answer;

    switch (answer)
    {
    case 'Y':
    case 'y':
        std::cout << "DONE" << "\n";
        break;
    case 'N':
    case 'n':
        std::cout << "NOT DONE" << "\n";
        break;
    default:
        std::cout << "INVALID INPUT" "\n";
        break;
    }

    std::cin.ignore(100,'\n');
    std::cout << "Press Any To Continue" << "\n";
    std::cin.get();
    
    return 0;
}