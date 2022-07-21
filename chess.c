#include "chess.h"


void Menu()
{
    printf("#########################\n");
    printf("###  1.play   0.exit  ###\n");
    printf("#########################\n");
    printf("请输入你的选择:>>\n");
}

//棋子坐标
//棋子输入坐标
int board_x = 0;//行 row
int board_y = 0;//列 col    
//棋子真实坐标
int board_rel_x = 0;//row
int board_rel_y = 0;//col

//下棋函数
void Player_Move(int board[][COL], int row, int col, player person)
{
    printf("player%d 下棋\n>>", person); 
    while(1) 
    {
        scanf("%d %d", &board_x, &board_y);

        //将坐标转换为真实坐标
        board_rel_x = board_x - 1;
        board_rel_y = board_y - 1;
        //判断位置是否合法
        if(board_rel_x < 0 || board_rel_x > row || board_rel_y < 0 || board_rel_y > col)
        {
            //报告位置不合法
            printf("输入位置超越棋盘边界，输入错误，请重新输入\n>>");
        }
        else
        {
            //位置合法,符号写入数组
            switch(person)
            {
                case Player1:
                    board[board_rel_x][board_rel_y] = Player1;
                    break;
                case player2:
                    board[board_rel_x][board_rel_y] = player2;
                    break;
                default:
                    //do nothing
                    break;
            }
        }
    }

} 

int Board_count(int board[][COL], Director Dir)
{
    int _x = board_rel_x;
    int _y = board_rel_y;
    int count = 0;//计数变量
    while(1)
    {
        switch(Dir)
        {
            case UP:
                _y--;
                break;
            case DOWN:
                _y++;
                break;
            case LEFT:
                _x--;
                break;
            case RIGHT:
                _x++;
                break;
            case LEFT_UP:
                _x--, _y--;
                break;
            case RIGHT_DOWN:
                _x++, _y++;
                break;
            case RIGHT_UP:
                _x++, _y--;
                break;
            case LEFT_DOWN:
                _x--, _y++;
        }
        //判断所加位置是否合法
        if(board[_x][_y] != board[board_rel_x][board_rel_y])
        {
            //不合法
            //跳出循环
            break;
        }
        else//合法
        {
            count++;
        }
    }
    return count;
}

//函数判断
int Judge(int Board[][COL], player person)
{
    //计算四个主方向的连续的坐标
    int up_down_count = Board_count(Board, UP) + Board_count(Board,DOWN) + 1;
    int left_right_count = Board_count(Board, LEFT) + Board_count(Board, RIGHT) + 1;
    int left_up_right_down_count = Board_count(Board, LEFT_UP) + Board_count(Board, RIGHT_DOWN) + 1;     
    int right_up_left_down_count = Board_count(Board, LEFT_DOWN) + Board_count(Board, RIGHT_UP) + 1;
    //一方胜利
    if(up_down_count >= 5 || left_right_count >= 5 || left_up_right_down_count >= 5 || right_up_left_down_count >= 5)
    {
        if(person == Player1)   
        {
            return Player1_Win;
        }
        else
        {
            return Player2_Win;
        }
    }
    //继续
    else
    {
        int i = 0;
        int j = 0;
        for(; i < ROW; i++)
        {
            for(; j < COL; j++)
            {
                Board[i][j] != 0;
                return Continue;
            }
        }
    }
    //平局
    return Draw;
}

void Display_KeyBoard(int Board[][COL], int row, int col)
{
    //显示第一行行号
    int fir_i = 0;
    printf("   ");//空三个字符
    for(fir_i = 1; fir_i <= row; fir_i++)
    {
        //输出行号
        printf("%3d", fir_i);
    }
    printf("\n");//换行输出棋盘
    //棋盘
    int i = 0;//主棋盘计数行
    int j = 0;//主棋盘计数列

    for(i = 0; i < col; i++)
    {
        //输出行号
        printf("%3d", i + 1);
        for(j = 0; j < row; j++)
        {
            switch (Board[j][i])
            {
            case 0:
                printf(" · ");
                break;
            case Player1:
                printf(" ? ");
                break;
            case player2:
                printf(" ? ");
                break;
            default:
                //Do nothing
                break;
            }    
        }
        printf("\n");
    }
}    
void game()
{
    //创建棋盘数组
    int Board[ROW][COL];
    //init board
    memset(Board, 0, sizeof(Board));
    while(1)
    {
        //显示棋盘
        Display_KeyBoard(Board, ROW, COL);
        //玩家1下棋
        Player_Move(Board, ROW, COL, Player1);

        int Judge_Player1 = Judge(Board, Player1);       //判断是否继续
        if(Judge_Player1 != Continue)
        {
            switch(Judge_Player1)
            {
                case Player1_Win:
                    printf("游戏结束,玩家1胜利\n");
                    break;
                case Player2_Win:
                    printf("游戏结束,玩家2胜利\n");
                    break;
                case Draw:
                    printf("平局,和气生财\n");
                    break;
                default:
                    // Do nothing
                    break;
            }
        }       
        //显示棋盘
        Display_KeyBoard(Board, ROW, COL);
        //玩家2下棋
        Player_Move(Board, ROW, COL, player2);
        int Judge_Player2 = Judge(Board, player2);
        //判断是否继续
        if(Judge_Player2 != Continue)
        {
            switch(Judge_Player2)
            {
                case Player1_Win:
                    printf("游戏结束,玩家1胜利\n");
                    break;
                case Player2_Win:
                    printf("游戏结束,玩家2胜利\n");
                    break;
                case Draw:
                    printf("平局,和气生财\n");
                    break;
                default:
                    //Do nothing
                    break;                    
            }
            break;
        }
    } 

}
