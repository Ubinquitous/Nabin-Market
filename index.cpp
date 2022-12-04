#include <stdio.h>
#include <malloc.h>
#include <unistd.h>
#include <windows.h>

/* 물품 목록 연결리스트 정의 */

typedef struct Node
{
    char name[50];
    int price;
    int date;
    int category;
    struct Node *next;
} Node;

/* 목록 선택 변수 */

int userselect;

/* 물품 목록 연결리스트 선언 */

Node *head = (Node *)malloc(sizeof(Node));
/* 연결리스트 초기화 변수 */

void init()
{
    head->next = NULL;
}

/* 물품 추가 함수 */

void deleteItem(Node *heads)
{
    Node *DateSortItem[1000];
    Node *temp[2];
    int i = 0, count = 0;
    struct Node *countHead = head;

    heads = heads->next;

    /* 배열에 물품 목록 담기 */
    while (heads != NULL)
    {
        DateSortItem[i] = heads;
        heads = heads->next;
        i++;
    }

    /* 물품 개수 구하기 */
    while (countHead != NULL)
    {
        count++;
        countHead = countHead->next;
    }

    /* 버블 정렬 */
    for (int i = count - 2; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (DateSortItem[j]->date > DateSortItem[j + 1]->date)
            {
                temp[0] = DateSortItem[j];
                DateSortItem[j] = DateSortItem[j + 1];
                DateSortItem[j + 1] = temp[0];
            }
        }
    }
    system("cls");
    printf("물품명, 물품 가격, 등록일, 카테고리\n");
    for (int i = 0; i < count - 1; i++)
    {
        /* 카테고리가 음료면 */
        if (DateSortItem[i]->category == 1)
        {
            printf("[%d]%s, %d, %02d-%02d-%02d, 음료\n", i + 1, DateSortItem[i]->name, DateSortItem[i]->price, DateSortItem[i]->date / 10000, DateSortItem[i]->date / 100 % 100, DateSortItem[i]->date % 100, DateSortItem[i]->category);
        }
        /* 카테고리가 과자면 */
        else if (DateSortItem[i]->category == 2)
        {
            printf("[%d]%s, %d, %02d-%02d-%02d, 과자\n", i + 1, DateSortItem[i]->name, DateSortItem[i]->price, DateSortItem[i]->date / 10000, DateSortItem[i]->date / 100 % 100, DateSortItem[i]->date % 100, DateSortItem[i]->category);
        }

        /* 카테고리가 과일이면 */
        else if (DateSortItem[i]->category == 3)
        {
            printf("[%d]%s, %d, %02d-%02d-%02d, 과일\n", i + 1, DateSortItem[i]->name, DateSortItem[i]->price, DateSortItem[i]->date / 10000, DateSortItem[i]->date / 100 % 100, DateSortItem[i]->date % 100, DateSortItem[i]->category);
        }

        /* 카테고리가 고기면 */
        else if (DateSortItem[i]->category == 4)
        {
            printf("[%d]%s, %d, %02d-%02d-%02d, 고기\n", i + 1, DateSortItem[i]->name, DateSortItem[i]->price, DateSortItem[i]->date / 10000, DateSortItem[i]->date / 100 % 100, DateSortItem[i]->date % 100, DateSortItem[i]->category);
        }

        /* 카테고리가 라면이면 */
        else if (DateSortItem[i]->category == 5)
        {
            printf("[%d]%s, %d, %02d-%02d-%02d, 라면\n", i + 1, DateSortItem[i]->name, DateSortItem[i]->price, DateSortItem[i]->date / 10000, DateSortItem[i]->date / 100 % 100, DateSortItem[i]->date % 100, DateSortItem[i]->category);
        }
    }

    printf("\n\n삭제하고 싶은 상품의 번호를 선택해주세요\n");
    int index;
    scanf("%d", &index);

    if (index == 1)
    {
        Node *temp2 = head;
        head = head->next;
        free(temp2);
        return;
    }

    Node *temp1 = head;
    Node *prev = nullptr;
    for (int i = 0; i < index; i++)
    {
        prev = temp1;
        temp1 = temp1->next;
    }

    prev->next = temp1->next;
    free(temp1);
    system("cls");
}

Node *insertItem()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    system("cls");
    printf("\n물품 추가 ───────\n\n");

    try
    {
        printf("추가할 물품명을 입력하세요 : ");
        scanf("%s", (newNode->name));

        printf("물품의 가격을 입력하세요 : ");
        scanf("%d", &(newNode->price));

        printf("물품의 등록일을 입력하세요 (ex: 2022년 11월 7일 = 221107) : ");
        scanf("%d", &(newNode->date));

        printf("물품의 카테고리를 정해주세요 :: \n");
        printf(" * 음료 ( 1을 누르세요 )\n");
        printf(" * 과자 ( 2를 누르세요 )\n");
        printf(" * 과일 ( 3을 누르세요 )\n");
        printf(" * 고기 ( 4를 누르세요 )\n");
        printf(" * 라면 ( 5를 누르세요 )\n");
        printf("카테고리를 선택하세요 : ");
        scanf("%d", &(newNode->category));

        if ((newNode->category) <= 5 && (newNode->category) >= 1)
        {
            system("cls");
            printf("%s(이)가 추가되었습니다!\n\n", (newNode->name));
        }
        else
        {
            throw -1;
        }
    }
    catch (int error)
    {
        printf("오류! 잘못된 입력값입니다. 다시 시도해주세요.\n");
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

/* 물품 검색 함수 */

void findItem(Node *heads)
{
    system("cls");
    int choice = 0;
    printf("물품 검색 페이지 ───────\n\n");
    printf(" * 등록일로 검색 ( 1을 누르세요 )\n");
    printf(" * 가격으로 검색 ( 2를 누르세요 )\n\n");
    printf("메뉴를 선택하세요 : ");
    scanf("%d", &choice);
    system("cls");

    /* 등록일로 검색 */
    if (choice == 1)
    {
        int date = 0;
        printf("검색할 등록일을 입력하세요 (ex: 2022년 11월 7일 = 221107) : ");
        scanf("%d", &date);
        system("cls");
        printf("물품명, 물품 가격, 등록일, 카테고리\n");
        Node *DateSearchItem[1000];
        int i = 0, count = 0;
        struct Node *countHead = head;
        heads = heads->next;
        while (heads != NULL)
        {
            DateSearchItem[i] = heads;
            heads = heads->next;
            i++;
        }
        while (countHead != NULL)
        {
            count++;
            countHead = countHead->next;
        }

        for (int i = 0; i < count - 1; i++)
        {
            if (DateSearchItem[i]->date == date)
            {
                printf("%s, %d, %02d-%02d-%02d, 음료\n", DateSearchItem[i]->name, DateSearchItem[i]->price, DateSearchItem[i]->date / 10000, DateSearchItem[i]->date / 100 % 100, DateSearchItem[i]->date % 100, DateSearchItem[i]->category);
            }
        }
        printf("\n\n** 확인하셨다면 아무 키나 입력해주세요. **\n");
        char a[300];
        scanf("%s", &a);
        system("cls");
    }
    /* 가격으로 검색 */
    else if (choice == 2)
    {
        int price = 0;
        printf("검색할 가격을 입력하세요 : ");
        scanf("%d", &price);
        system("cls");
        printf("물품명, 물품 가격, 등록일, 카테고리\n");
        Node *DatePriceItem[1000];
        int i = 0, count = 0;
        struct Node *countHead = head;
        heads = heads->next;
        while (heads != NULL)
        {
            DatePriceItem[i] = heads;
            heads = heads->next;
            i++;
        }
        while (countHead != NULL)
        {
            count++;
            countHead = countHead->next;
        }

        for (int i = 0; i < count - 1; i++)
        {
            if (DatePriceItem[i]->price == price)
            {
                printf("%s, %d, %02d-%02d-%02d, 음료\n", DatePriceItem[i]->name, DatePriceItem[i]->price, DatePriceItem[i]->date / 10000, DatePriceItem[i]->date / 100 % 100, DatePriceItem[i]->date % 100, DatePriceItem[i]->category);
            }
        }
        printf("\n\n** 확인하셨다면 아무 키나 입력해주세요. **\n");
        char a[300];
        scanf("%s", &a);
        system("cls");
    }
}

/* 물품 목록 조회 함수 */

void showAllItem(Node *heads)
{
    system("cls");
    int choice = 0;
    printf("물품 조회 페이지 ───────\n\n");
    printf(" * 등록일순 조회 ( 1을 누르세요 )\n");
    printf(" * 가격순 조회 ( 2를 누르세요 )\n");
    printf(" * 카테고리별 조회 ( 3을 누르세요 )\n\n");
    printf("메뉴를 선택하세요 : ");
    scanf("%d", &choice);
    system("cls");

    /* 등록일순 조회 */

    if (choice == 1)
    {
        Node *DateSortItem[1000];
        Node *temp[2];
        int i = 0, count = 0;
        struct Node *countHead = head;

        heads = heads->next;

        /* 배열에 물품 목록 담기 */
        while (heads != NULL)
        {
            DateSortItem[i] = heads;
            heads = heads->next;
            i++;
        }

        /* 물품 개수 구하기 */
        while (countHead != NULL)
        {
            count++;
            countHead = countHead->next;
        }

        /* 버블 정렬 */
        for (int i = count - 2; i > 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (DateSortItem[j]->date > DateSortItem[j + 1]->date)
                {
                    temp[0] = DateSortItem[j];
                    DateSortItem[j] = DateSortItem[j + 1];
                    DateSortItem[j + 1] = temp[0];
                }
            }
        }
        printf("물품명, 물품 가격, 등록일, 카테고리\n");
        for (int i = 0; i < count - 1; i++)
        {
            /* 카테고리가 음료면 */
            if (DateSortItem[i]->category == 1)
            {
                printf("%s, %d, %02d-%02d-%02d, 음료\n", DateSortItem[i]->name, DateSortItem[i]->price, DateSortItem[i]->date / 10000, DateSortItem[i]->date / 100 % 100, DateSortItem[i]->date % 100, DateSortItem[i]->category);
            }
            /* 카테고리가 과자면 */
            else if (DateSortItem[i]->category == 2)
            {
                printf("%s, %d, %02d-%02d-%02d, 과자\n", DateSortItem[i]->name, DateSortItem[i]->price, DateSortItem[i]->date / 10000, DateSortItem[i]->date / 100 % 100, DateSortItem[i]->date % 100, DateSortItem[i]->category);
            }

            /* 카테고리가 과일이면 */
            else if (DateSortItem[i]->category == 3)
            {
                printf("%s, %d, %02d-%02d-%02d, 과일\n", DateSortItem[i]->name, DateSortItem[i]->price, DateSortItem[i]->date / 10000, DateSortItem[i]->date / 100 % 100, DateSortItem[i]->date % 100, DateSortItem[i]->category);
            }

            /* 카테고리가 고기면 */
            else if (DateSortItem[i]->category == 4)
            {
                printf("%s, %d, %02d-%02d-%02d, 고기\n", DateSortItem[i]->name, DateSortItem[i]->price, DateSortItem[i]->date / 10000, DateSortItem[i]->date / 100 % 100, DateSortItem[i]->date % 100, DateSortItem[i]->category);
            }

            /* 카테고리가 라면이면 */
            else if (DateSortItem[i]->category == 5)
            {
                printf("%s, %d, %02d-%02d-%02d, 라면\n", DateSortItem[i]->name, DateSortItem[i]->price, DateSortItem[i]->date / 10000, DateSortItem[i]->date / 100 % 100, DateSortItem[i]->date % 100, DateSortItem[i]->category);
            }
        }

        printf("\n\n** 확인하셨다면 아무 키나 입력해주세요. **\n");
        char a[300];
        scanf("%s", &a);
        system("cls");
    }

    /* 가격순 조회 */
    else if (choice == 2)
    {
        Node *PriceSortItem[1000];
        Node *temp[2];
        int i = 0, count = 0;
        struct Node *countHead = head;

        /* 배열에 물품 목록 담기 */
        heads = heads->next;
        while (heads != NULL)
        {
            PriceSortItem[i] = heads;
            heads = heads->next;
            i++;
        }
        /* 물품 개수 구하기 */
        while (countHead != NULL)
        {
            count++;
            countHead = countHead->next;
        }
        /* 버블 정렬 */
        for (int i = count - 2; i > 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (PriceSortItem[j]->price > PriceSortItem[j + 1]->price)
                {
                    temp[0] = PriceSortItem[j];
                    PriceSortItem[j] = PriceSortItem[j + 1];
                    PriceSortItem[j + 1] = temp[0];
                }
            }
        }
        printf("물품명, 물품 가격, 등록일, 카테고리\n");
        for (int i = 0; i < count - 1; i++)
        {
            /* 카테고리가 음료면 */
            if (PriceSortItem[i]->category == 1)
            {
                printf("%s, %d, %02d-%02d-%02d, 음료\n", PriceSortItem[i]->name, PriceSortItem[i]->price, PriceSortItem[i]->date / 10000, PriceSortItem[i]->date / 100 % 100, PriceSortItem[i]->date % 100, PriceSortItem[i]->category);
            }
            /* 카테고리가 과자면 */
            else if (PriceSortItem[i]->category == 2)
            {
                printf("%s, %d, %02d-%02d-%02d, 과자\n", PriceSortItem[i]->name, PriceSortItem[i]->price, PriceSortItem[i]->date / 10000, PriceSortItem[i]->date / 100 % 100, PriceSortItem[i]->date % 100, PriceSortItem[i]->category);
            }
            /* 카테고리가 과일이면 */
            else if (PriceSortItem[i]->category == 3)
            {
                printf("%s, %d, %02d-%02d-%02d, 과일\n", PriceSortItem[i]->name, PriceSortItem[i]->price, PriceSortItem[i]->date / 10000, PriceSortItem[i]->date / 100 % 100, PriceSortItem[i]->date % 100, PriceSortItem[i]->category);
            }
            /* 카테고리가 고기면 */
            else if (PriceSortItem[i]->category == 4)
            {
                printf("%s, %d, %02d-%02d-%02d, 고기\n", PriceSortItem[i]->name, PriceSortItem[i]->price, PriceSortItem[i]->date / 10000, PriceSortItem[i]->date / 100 % 100, PriceSortItem[i]->date % 100, PriceSortItem[i]->category);
            }
            /* 카테고리가 라면이면 */
            else if (PriceSortItem[i]->category == 5)
            {
                printf("%s, %d, %02d-%02d-%02d, 라면\n", PriceSortItem[i]->name, PriceSortItem[i]->price, PriceSortItem[i]->date / 10000, PriceSortItem[i]->date / 100 % 100, PriceSortItem[i]->date % 100, PriceSortItem[i]->category);
            }
        }

        printf("\n\n** 확인하셨다면 아무 키나 입력해주세요. **\n");
        char a[300];
        scanf("%s", &a);
        system("cls");
    }
    /* 카테고리별 조회 */
    else if (choice == 3)
    {
        int ctg = 0;
        printf("조회하실 카테고리를 입력해주세요.\n");
        printf(" * 음료 ( 1을 누르세요 )\n");
        printf(" * 과자 ( 2를 누르세요 )\n");
        printf(" * 과일 ( 3을 누르세요 )\n");
        printf(" * 고기 ( 4를 누르세요 )\n");
        printf(" * 라면 ( 5를 누르세요 )\n\n");
        printf("카테고리를 선택하세요 : ");
        scanf("%d", &ctg);
        system("cls");
        printf("물품명, 물품 가격, 등록일, 카테고리\n");

        /* 순차 탐색 */
        heads = heads->next;
        while (heads != NULL)
        {
            if (heads->category == ctg)
            {
                printf("%s, %d, %02d-%02d-%02d, 음료\n", heads->name, heads->price, heads->date / 10000, heads->date / 100 % 100, heads->date % 100, heads->category);
            }
            heads = heads->next;
        }
        printf("\n\n** 확인하셨다면 아무 키나 입력해주세요. **\n");
        char a[300];
        scanf("%s", &a);
        system("cls");
    }
    else
    {
        printf("오류! 잘못된 입력값입니다. 다시 시도해주세요.\n");
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
        /* 물품 개수 구하기 */
        int count = 0;
        struct Node *countHead = head;
        while (countHead != NULL)
        {
            count++;
            countHead = countHead->next;
        }

        printf("나빈 마켓 현황 ─────\n\n");

        printf(" * 나빈 마켓 현재 물품 개수 (데이터 개수) : %d\n", count - 1);
        printf(" * 나빈 마켓 현재 진열 공간 (메모리 크기) : %d\n\n", (count - 1) * (sizeof(head)));

        printf("나빈 마켓 메뉴 ─────\n\n");

        printf(" * 물품 목록 조회 ( 1을 누르세요 )\n");
        printf(" * 특정 물품 검색 ( 2를 누르세요 )\n");
        printf(" * 마켓 물품 추가 ( 3를 누르세요 )\n");
        printf(" * 마켓 물품 삭제 ( 4을 누르세요 )\n");
        printf(" * 물품 찜 & 구매 ( 5를 누르세요 )\n\n");
        printf("메뉴를 선택하세요 : ");
        scanf("%d", &userselect);

        if (userselect == 1) // 조회
        {
            showAllItem(head);
        }
        else if (userselect == 2) // 검색
        {
            findItem(head);
        }
        else if (userselect == 3) // 추가
        {
            insertItem();
        }
        else if (userselect == 4) // 삭제
        {
            deleteItem(head);
        }
        else if (userselect == 5) // 구매
        {
            /* buyItem(); */
        }
    }
}