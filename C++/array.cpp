#include <iostream>

int main()
{
    int num[10];
    std::cout << "请输入10个整数:\r\n";

    for (int i = 0; i < 10 ; i++)
    {
        std::cout << "请输入第" << i+1 << "个数据:";
        std::cin >> num[i];
    }
    
    int sum = 0;
    
    for (int j = 0; j < 10; j++)
    {
        sum += num[j];
    }

    std::cout << "总和是：" << sum << "\n";
    std::cout << "平均值是：" << sum / 10.0 << "\n";

    return 0;
}