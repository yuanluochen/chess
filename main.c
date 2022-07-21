#include "chess.h"

int main()
{
    int select = 1;
    while(select)
    {
        //输入选择
        Menu();
        //1.继续 0.离开
        scanf("%d", &select);
        switch(select)
        {
            case 1:
                //游玩
                game();
                break;
            case 0:
                printf("游戏结束\n");
                //离开
                break;
            default:
                printf("输入错误,请重新输入\n");
                break;
        }
    }
    return 0;
}