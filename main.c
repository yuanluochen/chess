#include "chess.h"

int main()
{
    int select = 1;
    while(select)
    {
        //����ѡ��
        Menu();
        //1.���� 0.�뿪
        scanf("%d", &select);
        switch(select)
        {
            case 1:
                //����
                game();
                break;
            case 0:
                printf("��Ϸ����\n");
                //�뿪
                break;
            default:
                printf("�������,����������\n");
                break;
        }
    }
    return 0;
}