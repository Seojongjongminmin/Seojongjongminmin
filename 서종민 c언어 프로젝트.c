#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CLS system("cls")
#pragma warning (disable : 4996) //scanf오류 방지
void main()
{

    char sel = 'H';
    int sum = 0;
    char selMenu[1000] = ""; //selmenu 선언

    while (1)
    {
        fflush(stdin); //입력 버퍼 지우기
        system("cls"); //화면 정리

        switch (sel)
        {
        case 'H':
            system("color e"); //색깔을 출력해줌
            printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━ \n");
            printf("┃    JONG MIN's shoppingmall                        \n");
            printf("┃      202104019 서종민                             \n");
            printf("┃    1. O U T E R                                   \n");
            printf("┃    2. T O P                                       \n");
            printf("┃    3. B O T T O M                                 \n");
            printf("┃    4. A C C E S S O R Y                           \n");
            printf("┃    5. Q & A                                       \n");
            printf("┃    M. 장바구니                                    \n");
            printf("┃    Q. 종 료                                       \n");
            printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━ \n");

            printf("▶메뉴를 선택하세요 : "); scanf("%c", &sel);

            if (sel == 'q' || sel == 'm') { sel -= 32; }
            if (sel == 'M')
            {
                char a[100];
                char b;
                printf("★장바구니에 담긴 총 가격★\n");
                printf("%s", selMenu);
                printf("$합계 : %d원$\n", sum);
                printf("결제 수단은 무통장 입금 또는 신용카드 결제로 이루어집니다. 무엇을 선택하시겠습니까?\n");
                scanf("%s", a);
                getchar();
                printf("결제하시겠습니까? (Y/n)\n");
                scanf("%c", &b);

                if (b == 'Y' || b == 'y') {
                    //Y또는 y를 입력할 경우
                    printf("결제해주셔서 감사합니다 ^ㅁ^ 좋은 하루 되세요~\n");
                } 
                else if (b == 'n') {
                    //n을 입력한 경우
                    printf("결제가 완료되지 않았습니다.\n ");
                }
                system("pause"); //중지

                sel = 'H'; //첫 화면으로 돌아가기
            }
            break; //스위치문 탈출

        case '1':
            while (1)
            {
                char sel1;

                fflush(stdin);
                system("cls");

                system("color d");
                printf("┏━━━━━━━━━━━━━━━━\n");
                printf("┃      O U T E R                 \n");
                printf("┃                                \n");
                printf("┃ 1.  코트     65000원           \n");
                printf("┃ 2.  숏패딩   70000원           \n");
                printf("┃ 3.  롱패딩   100000원          \n");
                printf("┃ 4.  항공점퍼 55000원           \n");
                printf("┃ 5.  무스탕   130000원          \n");
                printf("┃ H. 첫 페이지로                 \n");
                printf("┗━━━━━━━━━━━━━━━━\n");

                printf("▶원하는 아우터를 선택하세요 : "); scanf("%c", &sel1);
                if (sel1 == 'h') { sel1 -= 32; }
                if (sel1 == 'H') { sel = 'H'; break; }

                switch (sel1)
                {
                case '1':
                    sum = sum + 65000;
                    strcat(selMenu, "-코트(65000원)\n");
                    break;
                case '2':
                    sum = sum + 70000;
                    strcat(selMenu, "-숏패딩(70000원)\n");
                    break;
                case '3':
                    sum = sum + 100000;
                    strcat(selMenu, "-롱패딩(100000원)\n");
                    break;
                case '4':
                    sum = sum + 55000;
                    strcat(selMenu, "-항공점퍼(55000원)\n");
                    break;
                case '5':
                    sum = sum + 130000;
                    strcat(selMenu, "-무스탕(130000원)\n");
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
                printf("┏━━━━━━━━━━━━━━━━\n");
                printf("┃      T O P                     \n");
                printf("┃                                \n");
                printf("┃ 1. 옥스포드 셔츠  22000원      \n");
                printf("┃ 2. 슬림핏 니트  18000원        \n");
                printf("┃ 3. 오버핏 맨투맨  23000원      \n");
                printf("┃ 4. 오버핏 후드티  30000원      \n");
                printf("┃ H. 첫 페이지로                 \n");
                printf("┗━━━━━━━━━━━━━━━━\n");

                printf("▶원하는 상의를 선택하세요 : "); scanf("%c", &sel2);
                if (sel2 == 'h') { sel2 -= 32; } //조건문 sel2 -=32; 소문자를 대문자로 변환하는 코드
                if (sel2 == 'H') { sel = 'H'; break; }

                switch (sel2)
                {
                case '1':
                    sum = sum + 22000;
                    strcat(selMenu, "-옥스포드 셔츠(22000원)\n"); //문자열을 이어붙이는 함수
                    break;
                case '2':
                    sum = sum + 18000;
                    strcat(selMenu, "-슬림핏 니트(18000원)\n");
                    break;
                case '3':
                    sum = sum + 23000;
                    strcat(selMenu, "-오버핏 맨투맨(23000원)\n");
                    break;
                case '4':
                    sum = sum + 30000;
                    strcat(selMenu, "-오버핏 후드티(30000원)\n");
                    break;
                default:
                    break;
                }
            }
            break;

        case '3':
            while (1) // 단순한 조건문 반복문 
            {
                char sel3;

                fflush(stdin);
                system("cls");

                system("color b");
                printf("┏━━━━━━━━━━━━━━━━━━\n");
                printf("┃      B O T T O M                   \n");
                printf("┃                                    \n");
                printf("┃ 1. 데님팬츠 24500원                \n");
                printf("┃ 2. 세미와이드 핏 슬랙스 19500원    \n");
                printf("┃ 3. 츄리닝 조거팬츠 15500원         \n");
                printf("┃ H. 첫 페이지로                     \n");
                printf("┗━━━━━━━━━━━━━━━━━━\n");
                printf("▶원하는 바지를 선택해주세요 : "); scanf("%c", &sel3);
                if (sel3 == 'h') { sel3 -= 32; }
                if (sel3 == 'H') { sel = 'H'; break; }

                switch (sel3) //sel3을 선택할 경우 
                {
                case '1': //1번 선택
                    sum = sum + 24500;
                    strcat(selMenu, "- 데님팬츠(24500원)\n"); //두 문자열을 이어붙이는 함수
                    break;
                case '2':
                    sum = sum + 19500; //누적
                    strcat(selMenu, "-세미와이드 핏 슬랙스(19500원)\n");
                    break;
                case '3':
                    sum = sum + 15500;
                    strcat(selMenu, "-츄리닝 조거팬츠 (15500원)\n");
                    break;
                default:
                    break;
                }
            }
            break;
        case '4':
            while (1) //단순한 조건 반복문
            {
                char sel4;

                fflush(stdin);
                system("cls");

                system("color d");
                printf("┏━━━━━━━━━━━━━━━━━━━━━\n");
                printf("┃      ACCESSORY                           \n");
                printf("┃                                          \n");
                printf("┃ 1.  팬던트 곰돌이 목걸이 12000원         \n");
                printf("┃ 2.  단화 신발 23000원                    \n");
                printf("┃ 3.  백팩       34000원                   \n");
                printf("┃ 4.  로즈골드 팔찌 17500원                \n");
                printf("┃ 5.  뿔테 미니멀 안경테  12000원          \n");
                printf("┃ H. 첫 페이지로                           \n");
                printf("┗━━━━━━━━━━━━━━━━━━━━━\n");

                printf("▶원하는 상품을 선택하세요! : "); scanf("%c", &sel4);
                if (sel4 == 'h') { sel4 -= 32; }
                if (sel4 == 'H') { sel = 'H'; break; }

                switch (sel4)
                {
                case '1':
                    sum = sum + 12000;
                    strcat(selMenu, "-팬던트 곰돌이 목걸이 (12000원)\n");
                    break;
                case '2':
                    sum = sum + 23000;
                    strcat(selMenu, "-단화 신발 (23000원)\n");
                    break;
                case '3':
                    sum = sum + 34000;
                    strcat(selMenu, "-백팩  (34000원)\n");
                    break;
                case '4':
                    sum = sum + 17500;
                    strcat(selMenu, "-로즈골드 팔찌 (17500원)\n");
                    break;
                case '5':
                    sum = sum + 12000;
                    strcat(selMenu, "-뿔테 미니멀 안경테  (12000원)\n");
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
                printf("┏━━━━━━━━━━━━━━━━━━━━━\n");
                printf("┃                Q&A                        \n");
                printf("┃    1. 상품 문의                          \n");
                printf("┃    2. 배송 문의                          \n");
                printf("┃    3. 기타 문의                          \n");
                printf("┃    H. 첫 페이지로                        \n");
                printf("┗━━━━━━━━━━━━━━━━━━━━━\n");

                printf("▶원하는 문의를 선택하세요! : "); scanf("%c", &sel5);
                if (sel5 == 'h') { sel5 -= 32; }
                if (sel5 == 'H') { sel = 'H'; break; }

                switch (sel5)
                {
                case '1':

                    printf("상품 문의를 선택하셨습니다! 원하시는 문의 사항을 남겨주세요:\n");
                    getchar();
                    gets_s(answer, 100);

                    printf("문의 해주셔서 감사합니다 ^^;; 차후에 상담사가 확인 후 연락 드리겠습니다! 더욱 좋은 서비스로 보답하겠습니다! (처음으로 돌아가시려면 아무 키나 눌러주세요!)\n");
                    scanf("%c", &a);

                    break;
                case '2':

                    printf("배송 문의를 선택하셨습니다! 배송은 보통 상품 구매가 완료되면 1~2일 후 발송 시작합니다!:\n");
                    getchar();
                    gets_s(answer, 100);

                    printf("문의 해주셔서 감사합니다 ^^;; 배송조회는 운송장 번호가 나오면 조회 가능합니다! (처음으로 돌아가시려면 아무 키나 눌러주세요!)\n");
                    scanf("%c", &a);
                    break;
                case '3':

                    printf("기타 문의를 선택하셨습니다! 상품 구매 적립금은 보통 상품의 3% 지급됩니다! 이 외에 문의 사항을 남겨주세요!:\n");
                    getchar();
                    gets_s(answer, 100);

                    printf("문의 해주셔서 감사합니다 ^^;; 오늘도 즐거운 하루 되세요^ㅁ^  (처음으로 돌아가시려면 아무 키나 눌러주세요!)\n");
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
        if (sel == 'Q') { printf("메뉴선택을 종료하겠습니다.\n"); break; }
    }
}