#pragma once
#include <stdio.h>
#include <string.h>

//定义棋盘大小
#define ROW 20
#define COL 20



//玩家
typedef enum player
{
    Player1 = 1,
    player2
}player;

//判断选项
typedef enum End
{
    Continue,
    Player1_Win,
    Player2_Win,
    Draw
}End;

//计数方向
typedef enum Director
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    LEFT_UP,
    RIGHT_DOWN,
    RIGHT_UP,
    LEFT_DOWN
}Director;

//菜单
void Menu();

//游戏函数
void game();