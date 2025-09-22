#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    int sum = 0;
    int i = 0;
    printf("请输入一串整数和任意数目的空格");
    while ( scanf("%d", &i) == 1 )
    {
        sum += i;
        while ((ch = getchar()) == ' ')
            ;
        if (ch == '\n')
        {
            break;
        }
        // ungetc(ch,stdin); //将变量ch中存放的字符退回给stdin输入流
        
        /* code */
    }
    printf("结果是：%d\r\n",sum);
    
}