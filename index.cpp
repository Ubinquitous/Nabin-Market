#include <stdio.h>
#include <malloc.h>
#include <unistd.h>
#include <windows.h>
<<<<<<< HEAD

/* ��ǰ ��� ���Ḯ��Ʈ ���� */

=======

int userselect;

/* define */
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
typedef struct Node
{
    char name[50];
    int price;
    int date;
    int category;
    struct Node *next;
} Node;

<<<<<<< HEAD
/* ��� ���� ���� */

int userselect;

/* ��ǰ ��� ���Ḯ��Ʈ ���� */

Node *head = (Node *)malloc(sizeof(Node));
/* ���Ḯ��Ʈ �ʱ�ȭ ���� */

=======
/* variable define*/

Node *head = (Node *)malloc(sizeof(Node));
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
void init()
{
    head->next = NULL;
}
<<<<<<< HEAD

/* ��ǰ �߰� �Լ� */

void deleteItem(Node *heads)
{
    Node *DateSortItem[1000];
    Node *temp[2];
        int i = 0, count = 0;
        struct Node *countHead = head;

        heads = heads->next;

        /* �迭�� ��ǰ ��� ��� */
        while (heads != NULL)
        {
            DateSortItem[i] = heads;
            heads = heads->next;
            i++;
        }

        /* ��ǰ ���� ���ϱ� */
        while (countHead != NULL)
        {
            count++;
            countHead = countHead->next;
        }

        /* ���� ���� */
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
        printf("��ǰ��, ��ǰ ����, �����, ī�װ�\n");
        for (int i = 0; i < count - 1; i++)
        {
            /* ī�װ��� ����� */
            if (DateSortItem[i]->category == 1)
            {
                printf("[%d]%s, %d, %02d-%02d-%02d, ����\n", i + 1,DateSortItem[i]->name, DateSortItem[i]->price, DateSortItem[i]->date / 10000, DateSortItem[i]->date / 100 % 100, DateSortItem[i]->date % 100, DateSortItem[i]->category);
            }
            /* ī�װ��� ���ڸ� */
            else if (DateSortItem[i]->category == 2)
            {
                printf("[%d]%s, %d, %02d-%02d-%02d, ����\n",i + 1, DateSortItem[i]->name, DateSortItem[i]->price, DateSortItem[i]->date / 10000, DateSortItem[i]->date / 100 % 100, DateSortItem[i]->date % 100, DateSortItem[i]->category);
            }

            /* ī�װ��� �����̸� */
            else if (DateSortItem[i]->category == 3)
            {
                printf("[%d]%s, %d, %02d-%02d-%02d, ����\n",i + 1, DateSortItem[i]->name, DateSortItem[i]->price, DateSortItem[i]->date / 10000, DateSortItem[i]->date / 100 % 100, DateSortItem[i]->date % 100, DateSortItem[i]->category);
            }

            /* ī�װ��� ���� */
            else if (DateSortItem[i]->category == 4)
            {
                printf("[%d]%s, %d, %02d-%02d-%02d, ���\n",i + 1, DateSortItem[i]->name, DateSortItem[i]->price, DateSortItem[i]->date / 10000, DateSortItem[i]->date / 100 % 100, DateSortItem[i]->date % 100, DateSortItem[i]->category);
            }

            /* ī�װ��� ����̸� */
            else if (DateSortItem[i]->category == 5)
            {
                printf("[%d]%s, %d, %02d-%02d-%02d, ���\n",i + 1, DateSortItem[i]->name, DateSortItem[i]->price, DateSortItem[i]->date / 10000, DateSortItem[i]->date / 100 % 100, DateSortItem[i]->date % 100, DateSortItem[i]->category);
            }
        }

        printf("\n\n�����ϰ� ���� ��ǰ�� ��ȣ�� �������ּ���\n");
        int index;
        scanf("%d", &index);

        if (index == 1)
        {
            Node* temp2 = head;
            head = head->next;
            free(temp2);
            return;
        }

    Node* temp1 = head;
	Node* prev = nullptr;
	for (int i = 0; i < index; i++)
	{
		prev = temp1;
		temp1 = temp1->next;
	}

	prev->next = temp1->next;
	free(temp1);
	}


Node *insertItem()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    system("cls");
    printf("\n��ǰ �߰� ��������������\n\n");

    try
    {
        printf("�߰��� ��ǰ���� �Է��ϼ��� : ");
        scanf("%s", (newNode->name));

        printf("��ǰ�� ������ �Է��ϼ��� : ");
        scanf("%d", &(newNode->price));

        printf("��ǰ�� ������� �Է��ϼ��� (ex: 2022�� 11�� 7�� = 221107) : ");
        scanf("%d", &(newNode->date));

        printf("��ǰ�� ī�װ��� �����ּ��� :: \n");
        printf(" * ���� ( 1�� �������� )\n");
        printf(" * ���� ( 2�� �������� )\n");
        printf(" * ���� ( 3�� �������� )\n");
        printf(" * ��� ( 4�� �������� )\n");
        printf(" * ��� ( 5�� �������� )\n");
        printf("ī�װ��� �����ϼ��� : ");
        scanf("%d", &(newNode->category));

        if ((newNode->category) <= 5 && (newNode->category) >= 1)
        {
            system("cls");
            printf("%s(��)�� �߰��Ǿ����ϴ�!\n\n", (newNode->name));
        }
        else
        {
            throw -1;
        }
    }
    catch (int error)
    {
        printf("����! �߸��� �Է°��Դϴ�. �ٽ� �õ����ּ���.\n");
    }

    newNode->next = NULL;

=======

/* insert item function */

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
            throw 0;
        }
    }
    catch (int error)
    {
        printf("오류! 잘못된 입력값입니다. 다시 시도해주세요.\n");
    }

    newNode->next = NULL;

>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
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

<<<<<<< HEAD
/* ��ǰ �˻� �Լ� */
=======
/* find item funtion */
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115

void findItem(Node *heads)
{
    system("cls");
    int choice = 0;
<<<<<<< HEAD
    printf("��ǰ �˻� ������ ��������������\n\n");
    printf(" * ����Ϸ� �˻� ( 1�� �������� )\n");
    printf(" * �������� �˻� ( 2�� �������� )\n\n");
    printf("�޴��� �����ϼ��� : ");
    scanf("%d", &choice);
    system("cls");

    /* ����Ϸ� �˻� */
    if (choice == 1)
    {
        int date = 0;
        printf("�˻��� ������� �Է��ϼ��� (ex: 2022�� 11�� 7�� = 221107) : ");
        scanf("%d", &date);
        system("cls");
        printf("��ǰ��, ��ǰ ����, �����, ī�װ�\n");
=======
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
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
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
<<<<<<< HEAD
                printf("%s, %d, %02d-%02d-%02d, ����\n", DateSearchItem[i]->name, DateSearchItem[i]->price, DateSearchItem[i]->date / 10000, DateSearchItem[i]->date / 100 % 100, DateSearchItem[i]->date % 100, DateSearchItem[i]->category);
            }
        }
        printf("\n\n** Ȯ���ϼ̴ٸ� �ƹ� Ű�� �Է����ּ���. **\n");
=======
                printf("%s, %d, %02d-%02d-%02d, 음료\n", DateSearchItem[i]->name, DateSearchItem[i]->price, DateSearchItem[i]->date / 10000, DateSearchItem[i]->date / 100 % 100, DateSearchItem[i]->date % 100, DateSearchItem[i]->category);
            }
        }
        printf("\n\n** 확인하셨다면 아무 키나 입력해주세요. **\n");
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
        char a[300];
        scanf("%s", &a);
        system("cls");
    }
<<<<<<< HEAD
    /* �������� �˻� */
    else if (choice == 2)
    {
        int price = 0;
        printf("�˻��� ������ �Է��ϼ��� : ");
        scanf("%d", &price);
        system("cls");
        printf("��ǰ��, ��ǰ ����, �����, ī�װ�\n");
=======
    else if (choice == 2)
    {
        /* 가격으로 검색 */
        int price = 0;
        printf("검색할 가격을 입력하세요 : ");
        scanf("%d", &price);
        system("cls");
        printf("물품명, 물품 가격, 등록일, 카테고리\n");
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
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
<<<<<<< HEAD
                printf("%s, %d, %02d-%02d-%02d, ����\n", DatePriceItem[i]->name, DatePriceItem[i]->price, DatePriceItem[i]->date / 10000, DatePriceItem[i]->date / 100 % 100, DatePriceItem[i]->date % 100, DatePriceItem[i]->category);
            }
        }
        printf("\n\n** Ȯ���ϼ̴ٸ� �ƹ� Ű�� �Է����ּ���. **\n");
=======
                printf("%s, %d, %02d-%02d-%02d, 음료\n", DatePriceItem[i]->name, DatePriceItem[i]->price, DatePriceItem[i]->date / 10000, DatePriceItem[i]->date / 100 % 100, DatePriceItem[i]->date % 100, DatePriceItem[i]->category);
            }
        }
        printf("\n\n** 확인하셨다면 아무 키나 입력해주세요. **\n");
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
        char a[300];
        scanf("%s", &a);
        system("cls");
    }
}

<<<<<<< HEAD
/* ��ǰ ��� ��ȸ �Լ� */
=======
/* show all item function */
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115

void showAllItem(Node *heads)
{
    system("cls");
    int choice = 0;
<<<<<<< HEAD
    printf("��ǰ ��ȸ ������ ��������������\n\n");
    printf(" * ����ϼ� ��ȸ ( 1�� �������� )\n");
    printf(" * ���ݼ� ��ȸ ( 2�� �������� )\n");
    printf(" * ī�װ��� ��ȸ ( 3�� �������� )\n\n");
    printf("�޴��� �����ϼ��� : ");
    scanf("%d", &choice);
    system("cls");

    /* ����ϼ� ��ȸ */
=======
    printf("물품 조회 페이지 ───────\n\n");
    printf(" * 등록일순 조회 ( 1을 누르세요 )\n");
    printf(" * 가격순 조회 ( 2를 누르세요 )\n");
    printf(" * 카테고리별 조회 ( 3을 누르세요 )\n\n");
    printf("메뉴를 선택하세요 : ");
    scanf("%d", &choice);
    system("cls");
    /* 등록일순 조회 */
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115

    if (choice == 1)
    {
        Node *DateSortItem[1000];
        Node *temp[2];
        int i = 0, count = 0;
        struct Node *countHead = head;

        heads = heads->next;
<<<<<<< HEAD

        /* �迭�� ��ǰ ��� ��� */
=======
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
        while (heads != NULL)
        {
            DateSortItem[i] = heads;
            heads = heads->next;
            i++;
        }
<<<<<<< HEAD

        /* ��ǰ ���� ���ϱ� */
=======
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
        while (countHead != NULL)
        {
            count++;
            countHead = countHead->next;
        }
<<<<<<< HEAD

        /* ���� ���� */
=======
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
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
<<<<<<< HEAD
        printf("��ǰ��, ��ǰ ����, �����, ī�װ�\n");
        for (int i = 0; i < count - 1; i++)
        {
            /* ī�װ��� ����� */
            if (DateSortItem[i]->category == 1)
            {
                printf("%s, %d, %02d-%02d-%02d, ����\n", DateSortItem[i]->name, DateSortItem[i]->price, DateSortItem[i]->date / 10000, DateSortItem[i]->date / 100 % 100, DateSortItem[i]->date % 100, DateSortItem[i]->category);
            }
            /* ī�װ��� ���ڸ� */
            else if (DateSortItem[i]->category == 2)
            {
                printf("%s, %d, %02d-%02d-%02d, ����\n", DateSortItem[i]->name, DateSortItem[i]->price, DateSortItem[i]->date / 10000, DateSortItem[i]->date / 100 % 100, DateSortItem[i]->date % 100, DateSortItem[i]->category);
            }

            /* ī�װ��� �����̸� */
            else if (DateSortItem[i]->category == 3)
            {
                printf("%s, %d, %02d-%02d-%02d, ����\n", DateSortItem[i]->name, DateSortItem[i]->price, DateSortItem[i]->date / 10000, DateSortItem[i]->date / 100 % 100, DateSortItem[i]->date % 100, DateSortItem[i]->category);
            }

            /* ī�װ��� ���� */
            else if (DateSortItem[i]->category == 4)
            {
                printf("%s, %d, %02d-%02d-%02d, ���\n", DateSortItem[i]->name, DateSortItem[i]->price, DateSortItem[i]->date / 10000, DateSortItem[i]->date / 100 % 100, DateSortItem[i]->date % 100, DateSortItem[i]->category);
            }

            /* ī�װ��� ����̸� */
            else if (DateSortItem[i]->category == 5)
            {
                printf("%s, %d, %02d-%02d-%02d, ���\n", DateSortItem[i]->name, DateSortItem[i]->price, DateSortItem[i]->date / 10000, DateSortItem[i]->date / 100 % 100, DateSortItem[i]->date % 100, DateSortItem[i]->category);
            }
        }

        printf("\n\n** Ȯ���ϼ̴ٸ� �ƹ� Ű�� �Է����ּ���. **\n");
=======
        printf("물품명, 물품 가격, 등록일, 카테고리\n");
        for (int i = 0; i < count - 1; i++)
        {
            if (DateSortItem[i]->category == 1)
            {
                printf("%s, %d, %02d-%02d-%02d, 음료\n", DateSortItem[i]->name, DateSortItem[i]->price, DateSortItem[i]->date / 10000, DateSortItem[i]->date / 100 % 100, DateSortItem[i]->date % 100, DateSortItem[i]->category);
            }
            else if (DateSortItem[i]->category == 2)
            {
                printf("%s, %d, %02d-%02d-%02d, 과자\n", DateSortItem[i]->name, DateSortItem[i]->price, DateSortItem[i]->date / 10000, DateSortItem[i]->date / 100 % 100, DateSortItem[i]->date % 100, DateSortItem[i]->category);
            }
            else if (DateSortItem[i]->category == 3)
            {
                printf("%s, %d, %02d-%02d-%02d, 과일\n", DateSortItem[i]->name, DateSortItem[i]->price, DateSortItem[i]->date / 10000, DateSortItem[i]->date / 100 % 100, DateSortItem[i]->date % 100, DateSortItem[i]->category);
            }
            else if (DateSortItem[i]->category == 4)
            {
                printf("%s, %d, %02d-%02d-%02d, 고기\n", DateSortItem[i]->name, DateSortItem[i]->price, DateSortItem[i]->date / 10000, DateSortItem[i]->date / 100 % 100, DateSortItem[i]->date % 100, DateSortItem[i]->category);
            }
            else if (DateSortItem[i]->category == 5)
            {
                printf("%s, %d, %02d-%02d-%02d, 라면\n", DateSortItem[i]->name, DateSortItem[i]->price, DateSortItem[i]->date / 10000, DateSortItem[i]->date / 100 % 100, DateSortItem[i]->date % 100, DateSortItem[i]->category);
            }
        }
        printf("\n\n** 확인하셨다면 아무 키나 입력해주세요. **\n");
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
        char a[300];
        scanf("%s", &a);
        system("cls");
    }
<<<<<<< HEAD

    /* ���ݼ� ��ȸ */
=======
    /* 가격순 조회 */
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
    else if (choice == 2)
    {
        Node *PriceSortItem[1000];
        Node *temp[2];
        int i = 0, count = 0;
        struct Node *countHead = head;

<<<<<<< HEAD
        /* �迭�� ��ǰ ��� ��� */
=======
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
        heads = heads->next;
        while (heads != NULL)
        {
            PriceSortItem[i] = heads;
            heads = heads->next;
            i++;
        }
<<<<<<< HEAD
        /* ��ǰ ���� ���ϱ� */
=======
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
        while (countHead != NULL)
        {
            count++;
            countHead = countHead->next;
        }
<<<<<<< HEAD
        /* ���� ���� */
=======
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
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
<<<<<<< HEAD
        printf("��ǰ��, ��ǰ ����, �����, ī�װ�\n");
        for (int i = 0; i < count - 1; i++)
        {
            /* ī�װ��� ����� */
            if (PriceSortItem[i]->category == 1)
            {
                printf("%s, %d, %02d-%02d-%02d, ����\n", PriceSortItem[i]->name, PriceSortItem[i]->price, PriceSortItem[i]->date / 10000, PriceSortItem[i]->date / 100 % 100, PriceSortItem[i]->date % 100, PriceSortItem[i]->category);
            }
            /* ī�װ��� ���ڸ� */
            else if (PriceSortItem[i]->category == 2)
            {
                printf("%s, %d, %02d-%02d-%02d, ����\n", PriceSortItem[i]->name, PriceSortItem[i]->price, PriceSortItem[i]->date / 10000, PriceSortItem[i]->date / 100 % 100, PriceSortItem[i]->date % 100, PriceSortItem[i]->category);
            }
            /* ī�װ��� �����̸� */
            else if (PriceSortItem[i]->category == 3)
            {
                printf("%s, %d, %02d-%02d-%02d, ����\n", PriceSortItem[i]->name, PriceSortItem[i]->price, PriceSortItem[i]->date / 10000, PriceSortItem[i]->date / 100 % 100, PriceSortItem[i]->date % 100, PriceSortItem[i]->category);
            }
            /* ī�װ��� ���� */
            else if (PriceSortItem[i]->category == 4)
            {
                printf("%s, %d, %02d-%02d-%02d, ���\n", PriceSortItem[i]->name, PriceSortItem[i]->price, PriceSortItem[i]->date / 10000, PriceSortItem[i]->date / 100 % 100, PriceSortItem[i]->date % 100, PriceSortItem[i]->category);
            }
            /* ī�װ��� ����̸� */
            else if (PriceSortItem[i]->category == 5)
            {
                printf("%s, %d, %02d-%02d-%02d, ���\n", PriceSortItem[i]->name, PriceSortItem[i]->price, PriceSortItem[i]->date / 10000, PriceSortItem[i]->date / 100 % 100, PriceSortItem[i]->date % 100, PriceSortItem[i]->category);
            }
        }

        printf("\n\n** Ȯ���ϼ̴ٸ� �ƹ� Ű�� �Է����ּ���. **\n");
=======
        printf("물품명, 물품 가격, 등록일, 카테고리\n");
        for (int i = 0; i < count - 1; i++)
        {
            if (PriceSortItem[i]->category == 1)
            {
                printf("%s, %d, %02d-%02d-%02d, 음료\n", PriceSortItem[i]->name, PriceSortItem[i]->price, PriceSortItem[i]->date / 10000, PriceSortItem[i]->date / 100 % 100, PriceSortItem[i]->date % 100, PriceSortItem[i]->category);
            }
            else if (PriceSortItem[i]->category == 2)
            {
                printf("%s, %d, %02d-%02d-%02d, 과자\n", PriceSortItem[i]->name, PriceSortItem[i]->price, PriceSortItem[i]->date / 10000, PriceSortItem[i]->date / 100 % 100, PriceSortItem[i]->date % 100, PriceSortItem[i]->category);
            }
            else if (PriceSortItem[i]->category == 3)
            {
                printf("%s, %d, %02d-%02d-%02d, 과일\n", PriceSortItem[i]->name, PriceSortItem[i]->price, PriceSortItem[i]->date / 10000, PriceSortItem[i]->date / 100 % 100, PriceSortItem[i]->date % 100, PriceSortItem[i]->category);
            }
            else if (PriceSortItem[i]->category == 4)
            {
                printf("%s, %d, %02d-%02d-%02d, 고기\n", PriceSortItem[i]->name, PriceSortItem[i]->price, PriceSortItem[i]->date / 10000, PriceSortItem[i]->date / 100 % 100, PriceSortItem[i]->date % 100, PriceSortItem[i]->category);
            }
            else if (PriceSortItem[i]->category == 5)
            {
                printf("%s, %d, %02d-%02d-%02d, 라면\n", PriceSortItem[i]->name, PriceSortItem[i]->price, PriceSortItem[i]->date / 10000, PriceSortItem[i]->date / 100 % 100, PriceSortItem[i]->date % 100, PriceSortItem[i]->category);
            }
        }
        printf("\n\n** 확인하셨다면 아무 키나 입력해주세요. **\n");
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
        char a[300];
        scanf("%s", &a);
        system("cls");
    }
<<<<<<< HEAD
    /* ī�װ��� ��ȸ */
    else if (choice == 3)
    {
        int ctg = 0;
        printf("��ȸ�Ͻ� ī�װ��� �Է����ּ���.\n");
        printf(" * ���� ( 1�� �������� )\n");
        printf(" * ���� ( 2�� �������� )\n");
        printf(" * ���� ( 3�� �������� )\n");
        printf(" * ��� ( 4�� �������� )\n");
        printf(" * ��� ( 5�� �������� )\n\n");
        printf("ī�װ��� �����ϼ��� : ");
        scanf("%d", &ctg);
        system("cls");
        printf("��ǰ��, ��ǰ ����, �����, ī�װ�\n");

        /* ���� Ž�� */
=======
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
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
        heads = heads->next;
        while (heads != NULL)
        {
            if (heads->category == ctg)
            {
<<<<<<< HEAD
                printf("%s, %d, %02d-%02d-%02d, ����\n", heads->name, heads->price, heads->date / 10000, heads->date / 100 % 100, heads->date % 100, heads->category);
            }
            heads = heads->next;
        }
        printf("\n\n** Ȯ���ϼ̴ٸ� �ƹ� Ű�� �Է����ּ���. **\n");
=======
                printf("%s, %d, %02d-%02d-%02d, 음료\n", heads->name, heads->price, heads->date / 10000, heads->date / 100 % 100, heads->date % 100, heads->category);
            }
            heads = heads->next;
        }
        printf("\n\n** 확인하셨다면 아무 키나 입력해주세요. **\n");
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
        char a[300];
        scanf("%s", &a);
        system("cls");
    }
    else
    {
<<<<<<< HEAD
        printf("����! �߸��� �Է°��Դϴ�. �ٽ� �õ����ּ���.\n");
=======
        printf("오류! 잘못된 입력값입니다. 다시 시도해주세요.\n");
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
    }
}

/* main function */

int main()
{
    init();
<<<<<<< HEAD
    printf("Nabin Market ��������������\n\n");
=======
    printf("Nabin Market ───────\n\n");
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115

    printf(" * 나빈 마켓에 오신 것을 환영합니다. \n");
    printf(" * 나빈 마켓은 C++로 구현한 매장 물품 관리 프로그램입니다. \n\n");

    while (1)
    {
<<<<<<< HEAD
        /* ��ǰ ���� ���ϱ� */
=======
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
        int count = 0;
        struct Node *countHead = head;
        while (countHead != NULL)
        {
            count++;
            countHead = countHead->next;
        }

<<<<<<< HEAD
        printf("���� ���� ��Ȳ ����������\n\n");

        printf(" * ���� ���� ���� ��ǰ ���� (������ ����) : %d\n", count - 1);
        printf(" * ���� ���� ���� ���� ���� (�޸� ũ��) : %d\n\n", (count - 1) * (sizeof(head)));

        printf("���� ���� �޴� ����������\n\n");

        printf(" * ��ǰ ��� ��ȸ ( 1�� �������� )\n");
        printf(" * Ư�� ��ǰ �˻� ( 2�� �������� )\n");
        printf(" * ���� ��ǰ �߰� ( 3�� �������� )\n");
        printf(" * ���� ��ǰ ���� ( 4�� �������� )\n");
        printf(" * ��ǰ �� & ���� ( 5�� �������� )\n\n");
        printf("�޴��� �����ϼ��� : ");
        scanf("%d", &userselect);

        if (userselect == 1) // ��ȸ
        {
            showAllItem(head);
        }
        else if (userselect == 2) // �˻�
        {
            findItem(head);
        }
        else if (userselect == 3) // �߰�
        {
            insertItem();
        }
        else if (userselect == 4) // ����
        {
            deleteItem(head);
        }
        else if (userselect == 5) // ����
=======
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

        if (userselect == 1)
        {
            showAllItem(head);
        }
        else if (userselect == 2)
        {
            findItem(head);
        }
        else if (userselect == 3)
        {
            insertItem();
        }
        else if (userselect == 4)
        {
            /* deleteItem(); */
        }
        else if (userselect == 5)
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
        {
            /* buyItem(); */
        }
    }
<<<<<<< HEAD
}
=======
}
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
