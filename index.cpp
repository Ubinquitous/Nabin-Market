#include <stdio.h>
#include <malloc.h>
#include <unistd.h>
int select;

/* define */
typedef struct Node
{
    char name[50];
    int price;
    char date[20];
    int category;
    struct Node *next;
} Node;

/* variable define*/

Node *head = (Node *)malloc(sizeof(Node));
void init()
{
    head->next = NULL;
}

/* screen clear function */

void clearScreen()
{
    const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
    write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}

/* insert item function */

Node *insertItem()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("\n물품 추가 ───────\n\n");

    printf("추가할 물품명을 입력하세요 : ");
    scanf("%s", (newNode->name));

    printf("물품의 가격을 입력하세요 : ");
    scanf("%d", &(newNode->price));

    printf("물품의 등록일을 입력하세요 : ");
    scanf("%s", (newNode->date));

    printf("물품의 카테고리를 정해주세요 :: \n");
    printf(" * 음료 ( 1을 누르세요 )\n");
    printf(" * 과자 ( 2를 누르세요 )\n");
    printf(" * 과일 ( 3을 누르세요 )\n");
    printf(" * 고기 ( 4를 누르세요 )\n");
    printf(" * 라면 ( 5를 누르세요 )\n");

    while (1)
    {
        printf("카테고리를 선택하세요 : ");
        scanf("%d", &(newNode->category));
        if ((newNode->category) <= 5 && (newNode->category) >= 1)
        {
            printf("%s(이)가 추가되었습니다!\n\n", (newNode->name));
            break;
        }
        else
        {
            printf("잘못된 값입니다! 다시 입력해주세요.\n");
        }
    }

    newNode->next = NULL;

    if (head->next == NULL)
    {
        head->next = newNode;
    }
    else
    {
        Node *nextNode = head;
        while (nextNode->next != NULL)
            nextNode = nextNode->next;

        nextNode->next = newNode;
    }
    return newNode;
}

/* show all item function */

void showAllItem(Node *heads)
{
    clearScreen();
    int choice = 0;
    printf("물품 조회 페이지 ───────\n\n");
    printf(" * 등록일순 조회 ( 1을 누르세요 )\n");
    printf(" * 가격순 조회 ( 2를 누르세요 )\n");
    printf(" * 카테고리별 조회 ( 3을 누르세요 )\n");
    printf("메뉴를 선택하세요 : ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("물품명\t\t\t가격\t\t\t등록일자\t\t\t카테고리\n");

        /* 배열에 삽입 후 퀵정렬 필요 */

        heads = heads->next;
        while (heads != NULL)
        {
            if (heads->category == 1)
            {
                /* 음료 */
            }
            else if (heads->category == 2)
            {
                /* 과자 */
            }
            else if (heads->category == 3)
            {
                /* 과일 */
            }
            else if (heads->category == 4)
            {
                /* 고기 */
            }
            else if (heads->category == 5)
            {
                /* 라면 */
            }
            printf("%s\t\t\t%d\t\t\t%s\t\t\t%s\n", heads->name, heads->price, heads->date, "TEST");
            heads = heads->next;
        }
        return;
    }
}

/* main function */

int main()
{
    init();
    printf("Nabin Market ───────\n\n");

    printf(" * 나빈 마켓에 오신 것을 환영합니다. \n");
    printf(" * 나빈 마켓은 C++로 구현한 매장 물품 관리 프로그램입니다. \n\n");

    while (1)
    {
        int count = 0;
        struct Node *countHead = head;
        while (countHead != NULL)
        {
            count++;
            countHead = countHead->next;
        }

        printf("나빈 마켓 현황 ─────\n\n");

        printf(" * 나빈 마켓 현재 물품 개수 (데이터 개수) : %d\n", count - 1);
        printf(" * 나빈 마켓 현재 진열 공간 (메모리 크기) : %d\n", (count - 1) * (sizeof(head)));

        printf("나빈 마켓 메뉴 ─────\n\n");

        printf(" * 물품 목록 조회 ( 1을 누르세요 )\n");
        printf(" * 마켓 물품 추가 ( 2를 누르세요 )\n");
        printf(" * 마켓 물품 삭제 ( 3을 누르세요 )\n");
        printf(" * 물품 찜 & 구매 ( 4를 누르세요 )\n\n");
        printf("메뉴를 선택하세요 : ");
        scanf("%d", &select);

        if (select == 1)
        {
            showAllItem(head);
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
}