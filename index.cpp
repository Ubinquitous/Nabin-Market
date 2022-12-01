#include <stdio.h>

int select;

/* define */

/* variable define*/

/* function */

void insertItem()
{
    printf("\n물품 추가 ───────\n\n");
    printf("추가할 물품명을 입력하세요 : ");
    /* scanf */
    printf("추가할 물품명을 입력하세요 : ");

    printf("물품의 가격을 입력하세요 : ");
    /* scanf */

    printf("물품의 등록일을 입력하세요 : ");
}

/* main function */

int main()
{
    printf("Nabin Market ───────\n\n");

    printf(" * 나빈 마켓에 오신 것을 환영합니다. \n");
    printf(" * 나빈 마켓은 C++로 구현한 매장 물품 관리 프로그램입니다. \n\n");

    printf("나빈 마켓 현황 ─────\n\n");

    printf(" * 나빈 마켓 현재 물품 개수 (데이터 개수) : %d\n", 17);
    printf(" * 나빈 마켓 현재 진열 공간 (메모리 크기) : %d\n", 17 * 4);

    printf("나빈 마켓 메뉴 ─────\n\n");

    printf(" * 물품 목록 조회 ( 1을 누르세요 )\n");
    printf(" * 마켓 물품 추가 ( 2를 누르세요 )\n");
    printf(" * 마켓 물품 삭제 ( 3을 누르세요 )\n");
    printf(" * 물품 찜 & 구매 ( 4를 누르세요 )\n\n");
    printf("메뉴를 선택하세요 : ");
    scanf("%d", &select);

    if (select == 1)
    {
        /* showAllItem(); */
    }
    else if (select == 2)
    {
        insertItem();
    }
    else if (select == 3)
    {
        /* deleteItem(); */
    }
    else if (select == 4)
    {
        /* selectItem(); */
    }
}