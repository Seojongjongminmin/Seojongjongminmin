#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CLS system("cls")
#pragma warning (disable : 4996) //scanf���� ����
void main()
{

    char sel = 'H';
    int sum = 0;
    char selMenu[1000] = ""; //selmenu ����

    while (1)
    {
        fflush(stdin); //�Է� ���� �����
        system("cls"); //ȭ�� ����

        switch (sel)
        {
        case 'H':
            system("color e"); //������ �������
            printf("���������������������������������������������������� \n");
            printf("��    JONG MIN's shoppingmall                        \n");
            printf("��      202104019 ������                             \n");
            printf("��    1. O U T E R                                   \n");
            printf("��    2. T O P                                       \n");
            printf("��    3. B O T T O M                                 \n");
            printf("��    4. A C C E S S O R Y                           \n");
            printf("��    5. Q & A                                       \n");
            printf("��    M. ��ٱ���                                    \n");
            printf("��    Q. �� ��                                       \n");
            printf("���������������������������������������������������� \n");

            printf("���޴��� �����ϼ��� : "); scanf("%c", &sel);

            if (sel == 'q' || sel == 'm') { sel -= 32; }
            if (sel == 'M')
            {
                char a[100];
                char b;
                printf("����ٱ��Ͽ� ��� �� ���ݡ�\n");
                printf("%s", selMenu);
                printf("$�հ� : %d��$\n", sum);
                printf("���� ������ ������ �Ա� �Ǵ� �ſ�ī�� ������ �̷�����ϴ�. ������ �����Ͻðڽ��ϱ�?\n");
                scanf("%s", a);
                getchar();
                printf("�����Ͻðڽ��ϱ�? (Y/n)\n");
                scanf("%c", &b);

                if (b == 'Y' || b == 'y') {
                    //Y�Ǵ� y�� �Է��� ���
                    printf("�������ּż� �����մϴ� ^��^ ���� �Ϸ� �Ǽ���~\n");
                } 
                else if (b == 'n') {
                    //n�� �Է��� ���
                    printf("������ �Ϸ���� �ʾҽ��ϴ�.\n ");
                }
                system("pause"); //����

                sel = 'H'; //ù ȭ������ ���ư���
            }
            break; //����ġ�� Ż��

        case '1':
            while (1)
            {
                char sel1;

                fflush(stdin);
                system("cls");

                system("color d");
                printf("����������������������������������\n");
                printf("��      O U T E R                 \n");
                printf("��                                \n");
                printf("�� 1.  ��Ʈ     65000��           \n");
                printf("�� 2.  ���е�   70000��           \n");
                printf("�� 3.  ���е�   100000��          \n");
                printf("�� 4.  �װ����� 55000��           \n");
                printf("�� 5.  ������   130000��          \n");
                printf("�� H. ù ��������                 \n");
                printf("����������������������������������\n");

                printf("�����ϴ� �ƿ��͸� �����ϼ��� : "); scanf("%c", &sel1);
                if (sel1 == 'h') { sel1 -= 32; }
                if (sel1 == 'H') { sel = 'H'; break; }

                switch (sel1)
                {
                case '1':
                    sum = sum + 65000;
                    strcat(selMenu, "-��Ʈ(65000��)\n");
                    break;
                case '2':
                    sum = sum + 70000;
                    strcat(selMenu, "-���е�(70000��)\n");
                    break;
                case '3':
                    sum = sum + 100000;
                    strcat(selMenu, "-���е�(100000��)\n");
                    break;
                case '4':
                    sum = sum + 55000;
                    strcat(selMenu, "-�װ�����(55000��)\n");
                    break;
                case '5':
                    sum = sum + 130000;
                    strcat(selMenu, "-������(130000��)\n");
                    break;
                default:
                    break;
                }
            }
            break;

        case '2':
            while (1)
            {
                char sel2;

                fflush(stdin);
                system("cls");

                system("color c");
                printf("����������������������������������\n");
                printf("��      T O P                     \n");
                printf("��                                \n");
                printf("�� 1. �������� ����  22000��      \n");
                printf("�� 2. ������ ��Ʈ  18000��        \n");
                printf("�� 3. ������ ������  23000��      \n");
                printf("�� 4. ������ �ĵ�Ƽ  30000��      \n");
                printf("�� H. ù ��������                 \n");
                printf("����������������������������������\n");

                printf("�����ϴ� ���Ǹ� �����ϼ��� : "); scanf("%c", &sel2);
                if (sel2 == 'h') { sel2 -= 32; } //���ǹ� sel2 -=32; �ҹ��ڸ� �빮�ڷ� ��ȯ�ϴ� �ڵ�
                if (sel2 == 'H') { sel = 'H'; break; }

                switch (sel2)
                {
                case '1':
                    sum = sum + 22000;
                    strcat(selMenu, "-�������� ����(22000��)\n"); //���ڿ��� �̾���̴� �Լ�
                    break;
                case '2':
                    sum = sum + 18000;
                    strcat(selMenu, "-������ ��Ʈ(18000��)\n");
                    break;
                case '3':
                    sum = sum + 23000;
                    strcat(selMenu, "-������ ������(23000��)\n");
                    break;
                case '4':
                    sum = sum + 30000;
                    strcat(selMenu, "-������ �ĵ�Ƽ(30000��)\n");
                    break;
                default:
                    break;
                }
            }
            break;

        case '3':
            while (1) // �ܼ��� ���ǹ� �ݺ��� 
            {
                char sel3;

                fflush(stdin);
                system("cls");

                system("color b");
                printf("��������������������������������������\n");
                printf("��      B O T T O M                   \n");
                printf("��                                    \n");
                printf("�� 1. �������� 24500��                \n");
                printf("�� 2. ���̿��̵� �� ������ 19500��    \n");
                printf("�� 3. �򸮴� �������� 15500��         \n");
                printf("�� H. ù ��������                     \n");
                printf("��������������������������������������\n");
                printf("�����ϴ� ������ �������ּ��� : "); scanf("%c", &sel3);
                if (sel3 == 'h') { sel3 -= 32; }
                if (sel3 == 'H') { sel = 'H'; break; }

                switch (sel3) //sel3�� ������ ��� 
                {
                case '1': //1�� ����
                    sum = sum + 24500;
                    strcat(selMenu, "- ��������(24500��)\n"); //�� ���ڿ��� �̾���̴� �Լ�
                    break;
                case '2':
                    sum = sum + 19500; //����
                    strcat(selMenu, "-���̿��̵� �� ������(19500��)\n");
                    break;
                case '3':
                    sum = sum + 15500;
                    strcat(selMenu, "-�򸮴� �������� (15500��)\n");
                    break;
                default:
                    break;
                }
            }
            break;
        case '4':
            while (1) //�ܼ��� ���� �ݺ���
            {
                char sel4;

                fflush(stdin);
                system("cls");

                system("color d");
                printf("��������������������������������������������\n");
                printf("��      ACCESSORY                           \n");
                printf("��                                          \n");
                printf("�� 1.  �Ҵ�Ʈ ������ ����� 12000��         \n");
                printf("�� 2.  ��ȭ �Ź� 23000��                    \n");
                printf("�� 3.  ����       34000��                   \n");
                printf("�� 4.  ������ ���� 17500��                \n");
                printf("�� 5.  ���� �̴ϸ� �Ȱ���  12000��          \n");
                printf("�� H. ù ��������                           \n");
                printf("��������������������������������������������\n");

                printf("�����ϴ� ��ǰ�� �����ϼ���! : "); scanf("%c", &sel4);
                if (sel4 == 'h') { sel4 -= 32; }
                if (sel4 == 'H') { sel = 'H'; break; }

                switch (sel4)
                {
                case '1':
                    sum = sum + 12000;
                    strcat(selMenu, "-�Ҵ�Ʈ ������ ����� (12000��)\n");
                    break;
                case '2':
                    sum = sum + 23000;
                    strcat(selMenu, "-��ȭ �Ź� (23000��)\n");
                    break;
                case '3':
                    sum = sum + 34000;
                    strcat(selMenu, "-����  (34000��)\n");
                    break;
                case '4':
                    sum = sum + 17500;
                    strcat(selMenu, "-������ ���� (17500��)\n");
                    break;
                case '5':
                    sum = sum + 12000;
                    strcat(selMenu, "-���� �̴ϸ� �Ȱ���  (12000��)\n");
                    break;
                default:
                    break;
                }
            }
            break;
        case '5':
            while (1)
            {
                char sel5;
                char a;

                char answer[100];


                getchar();
                system("cls");

                system("color d");
                printf("��������������������������������������������\n");
                printf("��                Q&A                        \n");
                printf("��    1. ��ǰ ����                          \n");
                printf("��    2. ��� ����                          \n");
                printf("��    3. ��Ÿ ����                          \n");
                printf("��    H. ù ��������                        \n");
                printf("��������������������������������������������\n");

                printf("�����ϴ� ���Ǹ� �����ϼ���! : "); scanf("%c", &sel5);
                if (sel5 == 'h') { sel5 -= 32; }
                if (sel5 == 'H') { sel = 'H'; break; }

                switch (sel5)
                {
                case '1':

                    printf("��ǰ ���Ǹ� �����ϼ̽��ϴ�! ���Ͻô� ���� ������ �����ּ���:\n");
                    getchar();
                    gets_s(answer, 100);

                    printf("���� ���ּż� �����մϴ� ^^;; ���Ŀ� ���簡 Ȯ�� �� ���� �帮�ڽ��ϴ�! ���� ���� ���񽺷� �����ϰڽ��ϴ�! (ó������ ���ư��÷��� �ƹ� Ű�� �����ּ���!)\n");
                    scanf("%c", &a);

                    break;
                case '2':

                    printf("��� ���Ǹ� �����ϼ̽��ϴ�! ����� ���� ��ǰ ���Ű� �Ϸ�Ǹ� 1~2�� �� �߼� �����մϴ�!:\n");
                    getchar();
                    gets_s(answer, 100);

                    printf("���� ���ּż� �����մϴ� ^^;; �����ȸ�� ����� ��ȣ�� ������ ��ȸ �����մϴ�! (ó������ ���ư��÷��� �ƹ� Ű�� �����ּ���!)\n");
                    scanf("%c", &a);
                    break;
                case '3':

                    printf("��Ÿ ���Ǹ� �����ϼ̽��ϴ�! ��ǰ ���� �������� ���� ��ǰ�� 3% ���޵˴ϴ�! �� �ܿ� ���� ������ �����ּ���!:\n");
                    getchar();
                    gets_s(answer, 100);

                    printf("���� ���ּż� �����մϴ� ^^;; ���õ� ��ſ� �Ϸ� �Ǽ���^��^  (ó������ ���ư��÷��� �ƹ� Ű�� �����ּ���!)\n");
                    scanf("%c", &a);
                    break;

                default:
                    break;
                }
            }
            break;

        default:
            sel = 'H';
            break;
        }
        if (sel == 'Q') { printf("�޴������� �����ϰڽ��ϴ�.\n"); break; }
    }
}