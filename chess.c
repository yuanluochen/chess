#include "chess.h"


void Menu()
{
    printf("#########################\n");
    printf("###  1.play   0.exit  ###\n");
    printf("#########################\n");
    printf("���������ѡ��:>>\n");
}

//��������
//������������
int board_x = 0;//�� row
int board_y = 0;//�� col    
//������ʵ����
int board_rel_x = 0;//row
int board_rel_y = 0;//col

//���庯��
void Player_Move(int board[][COL], int row, int col, player person)
{
    printf("player%d ����\n>>", person); 
    while(1) 
    {
        scanf("%d %d", &board_x, &board_y);

        //������ת��Ϊ��ʵ����
        board_rel_x = board_x - 1;
        board_rel_y = board_y - 1;
        //�ж�λ���Ƿ�Ϸ�
        if(board_rel_x < 0 || board_rel_x > row || board_rel_y < 0 || board_rel_y > col)
        {
            //����λ�ò��Ϸ�
            printf("����λ�ó�Խ���̱߽磬�����������������\n>>");
        }
        else
        {
            //λ�úϷ�,����д������
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
    int count = 0;//��������
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
        //�ж�����λ���Ƿ�Ϸ�
        if(board[_x][_y] != board[board_rel_x][board_rel_y])
        {
            //���Ϸ�
            //����ѭ��
            break;
        }
        else//�Ϸ�
        {
            count++;
        }
    }
    return count;
}

//�����ж�
int Judge(int Board[][COL], player person)
{
    //�����ĸ������������������
    int up_down_count = Board_count(Board, UP) + Board_count(Board,DOWN) + 1;
    int left_right_count = Board_count(Board, LEFT) + Board_count(Board, RIGHT) + 1;
    int left_up_right_down_count = Board_count(Board, LEFT_UP) + Board_count(Board, RIGHT_DOWN) + 1;     
    int right_up_left_down_count = Board_count(Board, LEFT_DOWN) + Board_count(Board, RIGHT_UP) + 1;
    //һ��ʤ��
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
    //����
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
    //ƽ��
    return Draw;
}

void Display_KeyBoard(int Board[][COL], int row, int col)
{
    //��ʾ��һ���к�
    int fir_i = 0;
    printf("   ");//�������ַ�
    for(fir_i = 1; fir_i <= row; fir_i++)
    {
        //����к�
        printf("%3d", fir_i);
    }
    printf("\n");//�����������
    //����
    int i = 0;//�����̼�����
    int j = 0;//�����̼�����

    for(i = 0; i < col; i++)
    {
        //����к�
        printf("%3d", i + 1);
        for(j = 0; j < row; j++)
        {
            switch (Board[j][i])
            {
            case 0:
                printf(" �� ");
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
    //������������
    int Board[ROW][COL];
    //init board
    memset(Board, 0, sizeof(Board));
    while(1)
    {
        //��ʾ����
        Display_KeyBoard(Board, ROW, COL);
        //���1����
        Player_Move(Board, ROW, COL, Player1);

        int Judge_Player1 = Judge(Board, Player1);       //�ж��Ƿ����
        if(Judge_Player1 != Continue)
        {
            switch(Judge_Player1)
            {
                case Player1_Win:
                    printf("��Ϸ����,���1ʤ��\n");
                    break;
                case Player2_Win:
                    printf("��Ϸ����,���2ʤ��\n");
                    break;
                case Draw:
                    printf("ƽ��,��������\n");
                    break;
                default:
                    // Do nothing
                    break;
            }
        }       
        //��ʾ����
        Display_KeyBoard(Board, ROW, COL);
        //���2����
        Player_Move(Board, ROW, COL, player2);
        int Judge_Player2 = Judge(Board, player2);
        //�ж��Ƿ����
        if(Judge_Player2 != Continue)
        {
            switch(Judge_Player2)
            {
                case Player1_Win:
                    printf("��Ϸ����,���1ʤ��\n");
                    break;
                case Player2_Win:
                    printf("��Ϸ����,���2ʤ��\n");
                    break;
                case Draw:
                    printf("ƽ��,��������\n");
                    break;
                default:
                    //Do nothing
                    break;                    
            }
            break;
        }
    } 

}
