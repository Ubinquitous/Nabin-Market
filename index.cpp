#include <stdio.h>
#include <malloc.h>
#include <unistd.h>
#include <windows.h>

/* ��ǰ ��� ���Ḯ��Ʈ ���� */

typedef struct Node
{
    char name[50];
    int price;
    int date;
    int category;
    struct Node *next;
} Node;

/* ��� ���� ���� */

int userselect;

/* ��ǰ ��� ���Ḯ��Ʈ ���� */

Node *head = (Node *)malloc(sizeof(Node));
/* ���Ḯ��Ʈ �ʱ�ȭ ���� */

void init()
{
    head->next = NULL;
}

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

/* ��ǰ �˻� �Լ� */

void findItem(Node *heads)
{
    system("cls");
    int choice = 0;
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
                printf("%s, %d, %02d-%02d-%02d, ����\n", DateSearchItem[i]->name, DateSearchItem[i]->price, DateSearchItem[i]->date / 10000, DateSearchItem[i]->date / 100 % 100, DateSearchItem[i]->date % 100, DateSearchItem[i]->category);
            }
        }
        printf("\n\n** Ȯ���ϼ̴ٸ� �ƹ� Ű�� �Է����ּ���. **\n");
        char a[300];
        scanf("%s", &a);
        system("cls");
    }
    /* �������� �˻� */
    else if (choice == 2)
    {
        int price = 0;
        printf("�˻��� ������ �Է��ϼ��� : ");
        scanf("%d", &price);
        system("cls");
        printf("��ǰ��, ��ǰ ����, �����, ī�װ�\n");
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
                printf("%s, %d, %02d-%02d-%02d, ����\n", DatePriceItem[i]->name, DatePriceItem[i]->price, DatePriceItem[i]->date / 10000, DatePriceItem[i]->date / 100 % 100, DatePriceItem[i]->date % 100, DatePriceItem[i]->category);
            }
        }
        printf("\n\n** Ȯ���ϼ̴ٸ� �ƹ� Ű�� �Է����ּ���. **\n");
        char a[300];
        scanf("%s", &a);
        system("cls");
    }
}

/* ��ǰ ��� ��ȸ �Լ� */

void showAllItem(Node *heads)
{
    system("cls");
    int choice = 0;
    printf("��ǰ ��ȸ ������ ��������������\n\n");
    printf(" * ����ϼ� ��ȸ ( 1�� �������� )\n");
    printf(" * ���ݼ� ��ȸ ( 2�� �������� )\n");
    printf(" * ī�װ��� ��ȸ ( 3�� �������� )\n\n");
    printf("�޴��� �����ϼ��� : ");
    scanf("%d", &choice);
    system("cls");

    /* ����ϼ� ��ȸ */

    if (choice == 1)
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
        char a[300];
        scanf("%s", &a);
        system("cls");
    }

    /* ���ݼ� ��ȸ */
    else if (choice == 2)
    {
        Node *PriceSortItem[1000];
        Node *temp[2];
        int i = 0, count = 0;
        struct Node *countHead = head;

        /* �迭�� ��ǰ ��� ��� */
        heads = heads->next;
        while (heads != NULL)
        {
            PriceSortItem[i] = heads;
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
                if (PriceSortItem[j]->price > PriceSortItem[j + 1]->price)
                {
                    temp[0] = PriceSortItem[j];
                    PriceSortItem[j] = PriceSortItem[j + 1];
                    PriceSortItem[j + 1] = temp[0];
                }
            }
        }
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
        char a[300];
        scanf("%s", &a);
        system("cls");
    }
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
        heads = heads->next;
        while (heads != NULL)
        {
            if (heads->category == ctg)
            {
                printf("%s, %d, %02d-%02d-%02d, ����\n", heads->name, heads->price, heads->date / 10000, heads->date / 100 % 100, heads->date % 100, heads->category);
            }
            heads = heads->next;
        }
        printf("\n\n** Ȯ���ϼ̴ٸ� �ƹ� Ű�� �Է����ּ���. **\n");
        char a[300];
        scanf("%s", &a);
        system("cls");
    }
    else
    {
        printf("����! �߸��� �Է°��Դϴ�. �ٽ� �õ����ּ���.\n");
    }
}

/* main function */

int main()
{
    init();
    printf("Nabin Market ��������������\n\n");

    printf(" * ���� ���Ͽ� ���� ���� ȯ���մϴ�. \n");
    printf(" * ���� ������ C++�� ������ ���� ��ǰ ���� ���α׷��Դϴ�. \n\n");

    while (1)
    {
        /* ��ǰ ���� ���ϱ� */
        int count = 0;
        struct Node *countHead = head;
        while (countHead != NULL)
        {
            count++;
            countHead = countHead->next;
        }

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
        {
            /* buyItem(); */
        }
    }
}
