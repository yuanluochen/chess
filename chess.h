#pragma once
#include <stdio.h>
#include <string.h>

//�������̴�С
#define ROW 20
#define COL 20



//���
typedef enum player
{
    Player1 = 1,
    player2
}player;

//�ж�ѡ��
typedef enum End
{
    Continue,
    Player1_Win,
    Player2_Win,
    Draw
}End;

//��������
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

//�˵�
void Menu();

//��Ϸ����
void game();